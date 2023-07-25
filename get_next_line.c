/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:15 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/25 16:41:55 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_join(char	*buffer, char *stash)
{
	char	*tmp;

	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	if (!stash)
	{
		stash = ft_calloc(1, sizeof(char));
		if (!stash)
			return (NULL);
	}
	tmp = ft_strjoin(buffer, stash);
	return (tmp);
}
/*
Deletes the first line (=line ending with \n) from stash
Copies chars from stash in new_stash without the first line
*/

char	*delete_first_line(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	if (!new_stash)
	{
		free (stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i + j] != '\0')
	{
		new_stash[j] = stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

/*
Search and retrieve the first line from stash
*/

char	*get_first_line(char *stash)
{
	char	*first_line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	first_line = ft_calloc(i + 2, sizeof(char));
	if (!first_line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		first_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		first_line[i] = stash[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}

/*
Read nbytes (= BUFFERSIZE) from the opened file indicated by fd
into buffer until \n or eof
Copy and append the bytes read from buffer to stash
*/

char	*read_line(int fd, char *stash)
{
	int		chars_read;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	chars_read = 1;
	while ((ft_strchr(stash, '\n') == 0) && chars_read != 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buffer);
			if (stash)
				free (stash);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		stash = ft_free_join(buffer, stash);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	new_line = get_first_line(stash);
	if (!new_line)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = delete_first_line(stash);
	return (new_line);
}

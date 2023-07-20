/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:15 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/20 13:47:24 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Deletes the first line (=line ending with newline char) from the stash
Copies the stash in new_stash without the first line
*/


char	*delete_first_line(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;
	
	i = 0;
	// find (the length of) the first line in stash
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	// if eol at index i before finding a newline > free stash
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	// allocate mem for new stash; len of new_stash = len old stash - len of first line
	new_stash = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
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
Search and retrieve the first line from the stash
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
Read nbytes determined by the BUFFERSIZE from the opened file indicated by fd.
Store the bytes read from buffer in stash. 
*/

char	*read_line(int fd, char *stash)
{
	int		chars_read;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), 1);
	chars_read = 1;
	// keep iterating through this loop until eof or new_line is found
	while((ft_strchr(stash, '\n') == 0) && chars_read != 0) 
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
		stash = free_and_join(buffer, stash);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash; 
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
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

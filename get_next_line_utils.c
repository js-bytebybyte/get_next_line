/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/19 18:42:34 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(int count, int size)
{
	char	*stash;
	int		i;
	
	stash = (char *)malloc(count * size);
	if (!stash)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		stash[i] = '\0';
		i++;
	}
	return (stash);
}

int	ft_strchr(const char *stash, const char c)
{
	int	i;

	if (stash == NULL)
		return (0);
	i = 0;
	while (stash[i] && (stash[i] != c))
		i++;
	// if newline char is found, stop the loop
	if (stash[i] == c)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*free_and_join(const char *buffer, char *stash)
{
	char	*temp;

	if (!stash)
		temp = ft_strjoin(buffer, "");
	else
	{
		temp = ft_strjoin(buffer, stash);
		free(stash);
	}
	return (temp);
}

char	*ft_strjoin(const char *buffer, const char *stash)
{
	char	*joined;
	int		i;
	int		j;
	
	if (!buffer)
		return (NULL);
	joined = ft_calloc(ft_strlen(buffer) + ft_strlen(stash) + 1, sizeof(char));
	i = 0;
	while (stash[i] != '\0')
	{
		joined[i] = stash[i];
		i++; 
	}
	j = 0;
	while (buffer[j] != '\0')
	{
		joined[i + j] = buffer[j];
		j++; 
	}
	joined[i + j] = '\0';
	return (joined);
}

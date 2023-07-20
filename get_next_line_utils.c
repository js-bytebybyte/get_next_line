/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/20 22:40:58 by jolandestee      ###   ########.fr       */
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

int	ft_strchr(char *stash, char c)
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

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*free_and_join(char *buffer, char *stash)
{
	char	*temp;

	temp = ft_strjoin(buffer, stash);
	if (!temp)
		return (NULL);
	free(stash);
	return (temp);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	char	*joined;
	int		i;
	int		j;
	
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
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

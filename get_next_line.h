/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:50:18 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/20 13:43:24 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
char	*free_and_join(char *buffer, char *stash);
char	*ft_strjoin(char *buffer, char *stash);
char	*ft_calloc(int count, int size);

size_t	ft_strlen(char *s);

int	ft_strchr(char *stash, char c);

#endif 
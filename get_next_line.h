/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:50:18 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/17 18:24:13 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
char	*free_and_join(const char *buffer, char *stash);
char	*ft_strjoin(const char *buffer, const char *stash);
char	*ft_calloc(int count, int size);

size_t	ft_strlen(const char *s);

int	ft_strchr(const char *stash, const char c);

#endif 
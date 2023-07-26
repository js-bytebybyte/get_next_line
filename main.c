/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/26 11:52:35 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* Read a normal txt file containing only alfanumeric chars */

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("1char.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			return (0);
// 		printf("%s", line);
// 	}
// 	return(0);
// }

int	main(void)
{
	char	*line;
	int 	fd1;
	int 	fd2;
	int 	fd3;

	fd1 = open("cat.txt", O_RDONLY);
	printf("fd = %d\n", fd1);
	line = get_next_line(fd1);
	printf("%s\n", line);
	fd2 = open("1char.txt", O_RDONLY);
	printf("fd = %d\n", fd2);
	line = get_next_line(fd2);
	printf("%s\n", line);
	fd3 = open("bla.txt", O_RDONLY);
	printf("fd = %d\n", fd3);
	line = get_next_line(fd3);
	printf("%s\n", line);
	line = get_next_line(fd1);
	printf("%s\n", line);
	line = get_next_line(fd2);
	printf("%s\n", line);
	line = get_next_line(fd3);
	printf("%s\n", line);
	return (0);
}


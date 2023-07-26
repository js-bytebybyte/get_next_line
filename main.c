/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/26 18:08:25 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* --------------- MANDATORY -------------*/

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("cat.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ; 
		printf("%s", line);
	}
	return(0);
}


/* ---------------- BONUS ----------------*/
// int	main(void)
// {
// 	char	*line;
// 	int 	fd1;
// 	int 	fd2;
// 	int 	fd3;

// 	fd1 = open("cat.txt", O_RDONLY);
//     printf("fd1 = %d\n", fd1);
//     fd2 = open("1char.txt", O_RDONLY);
//     printf("fd2 = %d\n", fd2);
//     fd3 = open("bla.txt", O_RDONLY);
//     printf("fd3 = %d\n", fd3);
// 	line = get_next_line(fd1);
// 	printf("fd: %d, line: %s\n", fd1, line);
// 	line = get_next_line(fd2);
// 	printf("fd: %d, line: %s\n", fd2, line);
// 	line = get_next_line(fd3);
// 	printf("fd: %d, line: %s\n", fd3, line);
// 	line = get_next_line(fd1);
// 	printf("fd: %d, line: %s\n", fd1, line);
// 	line = get_next_line(fd2);
// 	printf("fd: %d, line: %s\n", fd2, line);
// 	line = get_next_line(fd3);
// 	printf("fd: %d, line: %s\n", fd3, line);
// 	return (0);
// }


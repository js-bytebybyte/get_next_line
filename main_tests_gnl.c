/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/25 18:24:32 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* Read a normal txt file containing only alfanumeric chars */

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
		printf("%s", line);
	}
	return(0);
}

/* Read an empty file */

// int	main(void)
// {
// 	int	fd;

// 	fd = open("empty.txt", O_RDONLY);
// 	printf("fd = %d\n", fd);
// 	printf("The first line at the end of the program:%s\n", get_next_line(fd));
// 	return(0);
// }

/* use non valid fd */

// int	main(void)
// {
// 	printf("The first line at the end of the program:%s\n", get_next_line(42));
// 	return(0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/19 18:37:46 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* Read a normal txt file containing only alfanumeric chars */

int	main(void)
{
	int	fd;

	fd = open("numbers_lines.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("The first line - attempt 1: %s\n", get_next_line(fd));
	printf("fd = %d\n", fd);
	printf("The first line - attempt 2: %s\n", get_next_line(fd));
	printf("fd = %d\n", fd);
	printf("The first line - attempt 3: %s\n", get_next_line(fd));
	printf("fd = %d\n", fd);
	printf("The first line - attempt 4: %s\n", get_next_line(fd));
	return(0);
}

/* Read an empty file */

/*int main(void)
{
  int fd;

  fd = open("empty.txt", O_RDONLY);
  printf("fd = %d\n", fd);
  printf("The first line at the end of the program: %s\n", get_next_line(fd));
  return(0);   
}*/
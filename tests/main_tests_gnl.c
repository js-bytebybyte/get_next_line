/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:32:09 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/07/20 22:42:38 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* Read a normal txt file containing only alfanumeric chars */

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("cat.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	
	/*printf("The first line - attempt 1: %s\n", get_next_line(fd));
	printf("fd = %d\n", fd);
	printf("The first line - attempt 2: %s\n", get_next_line(fd));
	printf("fd = %d\n", fd);
	printf("The first line - attempt 3: %s\n", get_next_line(fd));
	printf("fd = %d\n", fd);
	printf("The first line - attempt 4: %s\n", get_next_line(fd));
	*/
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
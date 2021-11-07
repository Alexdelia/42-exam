/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:14:46 by adelille          #+#    #+#             */
/*   Updated: 2021/11/07 15:29:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	*file;
	char	*line;
    int		fd;

	if (ac != 2)
		file = strdup("gnl.c");
	else
		file = strdup(av[1]);
	if (!file)
		return (printf("Malloc error\n") * 0 + 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open \"%s\"\n", file);
		free(file);
		return (1);
	}

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(file);
	close(fd);
	return (0);
}

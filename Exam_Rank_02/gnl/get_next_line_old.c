/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:23:19 by adelille          #+#    #+#             */
/*   Updated: 2021/10/28 16:31:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(char **line)
{
	int		i;
	int		line_index;
	int		res;
	char	c;
	char	*tmp;

	res = 0;
	line_index = 1;
	if (!(*line = malloc(line_index)))
		return (-1);
	(*line)[0] = 0;
	while ((res = read(0, &c, 1)) && line_index++ && c != '\n')
	{
		if (!(tmp = malloc(line_index)))
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < line_index - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (res);
}

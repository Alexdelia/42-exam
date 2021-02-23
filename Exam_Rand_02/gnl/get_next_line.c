/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 05:55:00 by user42            #+#    #+#             */
/*   Updated: 2021/02/23 05:55:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *remains, char *buffer)
{
	char			*res;
	unsigned int	size;
	int				i;
	int				j;

	if (!remains && !buffer)
		return (NULL);
	size = ft_strlen(remains) + ft_strlen(buffer);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
		{
			res[j] = remains[i];
			i++;
			j++;
		}
		i = 0;
	}
	while (buffer[i])
	{
		res[j] = buffer[i];
		i++;
		j++;
	}
	res[size] = '\0';
	free((void *)remains);
	return (res);
}

char	*push_line(char *remains)
{
	int		i;
	char	*res;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		res[i] = remains[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*cut_next_line(char *remains)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	i++;
	while (remains[i])
	{
		res[i] = remains[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(remains);
	return (res);
}

int		get_next_line(char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remains;
	int			ret;
	int			fd;

	ret = 1;
	fd = 0;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && ret != 0)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	*line = push_line(remains);
	remains = cut_next_line(remains);
	return ((ret == 0) ? 0 : 1);
}

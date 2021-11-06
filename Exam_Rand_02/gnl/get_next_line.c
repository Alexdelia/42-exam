/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:45:11 by adelille          #+#    #+#             */
/*   Updated: 2021/11/06 12:32:15 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_strcpy_b(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		dst[i] = '\0';
		i++;
	}
}

char	*ft_strdup(char *str)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	ft_strcpy(res, str);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(&res[ft_strlen(s1)], s2);
	return (res);
}

int	ft_check_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = { 0 };
	char		*line;
	char		*to_free;
	int			i;
	int			size;
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(line = ft_strdup("")))
		return (NULL);
	if (buffer[0] == '\0')
		read(fd, buffer, BUFFER_SIZE);
	i = 0;
	res = 1;
	while (res > 0)
	{
		if ((i = ft_check_n(buffer)) != -1)
		{
			to_free = line;
			size = ft_strlen(line);
			line = ft_strjoin(line, buffer);
			free(to_free);
			line[size + i + 1] = '\0';
			ft_strcpy_b(buffer, &buffer[i + 1]);
			if (*line == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		else
		{
			to_free = line;
			line = ft_strjoin(line, buffer);
			free(to_free);
			res = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(line);
	return (NULL);
}

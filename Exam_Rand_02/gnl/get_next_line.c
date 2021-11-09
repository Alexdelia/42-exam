/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:03:21 by adelille          #+#    #+#             */
/*   Updated: 2021/11/09 16:34:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (-1);
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

	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, str);
	return (res);
}

char	*ft_strjoin_free(char *s1, char *s2, int f1, int f2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(&res[ft_strlen(s1)], s2);
	if (f1 == 1)
		free(s1);
	if (f2 == 1)
		free(s2);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			n;
	int			res;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	}
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buffer[0] == '\0')
		read(fd, buffer, BUFFER_SIZE);
	res = 1;
	while (res > 0)
	{
		n = ft_n(buffer);
		if (n > -1)
		{
			size = ft_strlen(line);
			line = ft_strjoin_free(line, buffer, 1, 0);
			if (!line)
				return (NULL);
			line[size + n + 1] = '\0';
			ft_strcpy_b(buffer, &buffer[n + 1]);
			return (line);
		}
		else
		{
			line = ft_strjoin_free(line, buffer, 1, 0);
			if (!line)
				return (NULL);
			res = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
	free(line);
	return (NULL);
}

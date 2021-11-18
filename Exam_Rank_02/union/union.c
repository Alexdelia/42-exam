/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 06:03:56 by adelille          #+#    #+#             */
/*   Updated: 2021/11/06 12:42:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_res(char *str, int len)
{
	
	if (len > 0)
	{
		write(1, str, len);
	}
	write(1, "\n", 1);
	return (0);
}

int		ft_in(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	res[256];

	if (ac != 3)
		return (ft_res("oui", -1));
	j = 0;
	i = 0;
	while (av[1][i])
	{
		if (ft_in(res, av[1][i]) == 0)
		{
			res[j] = av[1][i];
			j++;
		}
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		if (ft_in(res, av[2][i]) == 0)
		{
			res[j] = av[2][i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (ft_res(res, j));
}

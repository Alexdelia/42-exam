/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:53:03 by user42            #+#    #+#             */
/*   Updated: 2021/02/21 23:16:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putres(char *res, int len)
{
	write(1, res, len);
	write(1, "\n", 1);
	return (0);
}

int		ft_in(char c, char *str)
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
		return (ft_putres("oui", 0));
	i = 0;
	while (res[i])
	{
		res[i] = '\0';
		i++;
	}
	i = 0;
	j = 0;
	while (av[1][i])
	{
		if (ft_in(av[1][i], av[2]) == 1 && ft_in(av[1][i], res) == 0)
		{
			res[j] = av[1][i];
			j++;
		}
		i++;
	}
	return (ft_putres(res, j));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:59:48 by adelille          #+#    #+#             */
/*   Updated: 2021/11/18 16:22:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef struct s_arg
{
	int		tmp;
}			t_arg;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ps(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_parse(t_arg *arg, char *file)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac != 2)
		return (ft_ps("Error: argument\n") * 0 + 1);
	if (ft_parse(&arg, av[1]) == 1)
		return (1);
	return (0);
}

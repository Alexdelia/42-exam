/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 15:22:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int ac, char **av, char *env)
{
	t_cmd	*cmd;
	int		ret;
	int		i;

	ret = EXIT_SICCESS;
	cmd = NULL;
	i = 1;
	while (i < ac)
	{
		parse(&cmd, av[i]);
		i++;
	}
	if (cmd)
		ret = exe(&cmd, env); // free in here
	return (ret);
}

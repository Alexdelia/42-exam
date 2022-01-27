/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:29 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 15:41:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	exec_cd(char **av)
{
	if (i != 2)
		ft_pser("error: cd: badarguments\n", 1);
	else if (chdir(av[1]))
	{
		ft_pser("error: cd: cannot change directory to", 1);
		ft_pser(av[1], 1);
		ft_pser("\n", 1);
	}
}

int	exec(char **av, int i, int tmp_fd, char **env)
{
	av[i] = NULL;
	close(tmp_fd);
	execve(av[0], av, env);
	ft_pser("error: cannot execute ");
	ft_pser(av[0]);
	ft_pser("\n");
	return (1);
}

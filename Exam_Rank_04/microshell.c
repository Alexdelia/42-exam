/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 18:11:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	fd[2];
	int	tmp_fd;
	int	i;

	(void)ac;
	pid = 0;
	tmp_fd = dup(STDIN_FILENO);
	i = 0;
	while (av[i] && av[i + 1]) // could use ac
	{
		av = &av[i + 1];
		i = 0;
		if (strcmp(av[0], "cd") == 0)
			exec_cd(av);
		else if (/* ; */)
		{

		}
		else if (/* | */)
		{

		}
	}
	// close fd/pipe
	return (0);
}

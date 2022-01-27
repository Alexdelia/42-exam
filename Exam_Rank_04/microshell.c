/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 18:25:37 by adelille         ###   ########.fr       */
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
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
			exec_cd(av, i);
		else if (av != &av[i] && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				if (exec(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, NULL, WUNTRACED);
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (av != &av[i] && strcmp(av[i], "|") == 0)
		{

		}
	}
	// close fd/pipe
	return (0);
}

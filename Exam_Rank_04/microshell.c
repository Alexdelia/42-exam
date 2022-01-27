/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 18:35:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	pipe[2];
	int	fd;
	int	i;

	(void)ac;
	//pid = 0;
	fd = dup(STDIN_FILENO);
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
				dup2(fd, STDIN_FILENO);
				if (exec(av, i, fd, env))
					return (1);
			}
			else
			{
				close(fd);
				waitpid(-1, NULL, WUNTRACED);
				fd = dup(STDIN_FILENO);
			}
		}
		else if (av != &av[i] && strcmp(av[i], "|") == 0)
		{
			pipe(pipe);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd, STDIN_FILENO);
				dup2(pipe[1], STDOUT_FILENO);
				close(pipe[0]);
				close(pipe[1]);
				if (exec(av, i, fd, env))
					return (1);
			}
			else
			{
				close(pipe[1]);
				close(fd);
				waitpid(-1, NULL, WUNTRACED);
				fd = dup(pipe[0]);
				close(pipe[0]);
			}
		}
	}
	close(fd);
	return (0);
}

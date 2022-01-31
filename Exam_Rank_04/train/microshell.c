/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:00:33 by adelille          #+#    #+#             */
/*   Updated: 2022/01/31 09:58:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

static void	ft_pser(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

static int	exec(char **av, int i, int fd, char **env)
{
	av[i] = NULL;
	close(fd);
	execve(av[0], av, env);
	ft_pser("error: cannot execute ");
	ft_pser(av[0]);
	ft_pser("\n");
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	pip[2];
	int	fd;
	int	i;

	(void)ac;
	fd = dup(STDIN_FILENO);
	i = 0;
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_pser("error: cd: bad arguments\n");
			else if (chdir(av[1]))
			{
				ft_pser("error: cd: cannot change directory to ");
				ft_pser(av[1]);
				ft_pser("\n");
			}
		}
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
			pipe(pip);
			pid = fork();
			if (pid == 0)
			{
				dup2(fd, STDIN_FILENO);
				dup2(pip[1], STDOUT_FILENO);
				close(pip[0]);
				close(pip[1]);
				if (exec(av, i, fd, env))
					return (1);
			}
			else
			{
				close(pip[1]);
				close(fd);
				waitpid(-1, NULL, WUNTRACED);
				fd = dup(pip[0]);
				close(pip[0]);
			}
		}
	}
	close(fd);
	if (TEST)
		while (1);
	return (0);
}

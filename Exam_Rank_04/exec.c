/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:29 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 22:12:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	exec_cd(t_cmd *cmd)
{
	if (cmd->len < 2)
		return (error("error: cd: badarguments\n", 1));
	else if (chdir(cmd->av[1]))
	{
		error("error: cd: cannot change directory to", 1);
		error(cmd->av[1], 1);
		return (error("\n", 1));
	}
	return (EXIT_SUCCESS);
}

int	exec_list(t_cmd **list, char **env)
{
	t_cmd	*cmd;
	int		ret;

	ret = EXIT_SUCCESS;
	cmd_rewind(list);
	while (*list)
	{
		cmd = *list;
		if (strcmp("cd", cmd->av[0]) == 0)
			ret = exec_cd(cmd);
		else
			ret = exec_cmd(cmd, env);
		if (!(*list)->next)
			break ;
		*list = (*list)->next;
	}
	return (ret);
}

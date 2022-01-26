/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:47:29 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 15:53:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	exec_cd(t_cmd *cmd)
{
	if (cmd->len < 2)
		return (ft_pser("error: cd: badarguments\n"));
	else if (chdir(cmd->av[1]))
	{
		ft_pser("error: cd: cannot change directory to");
		ft_pser(cmd->av[1]);
		return (ft_pser("\n");
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

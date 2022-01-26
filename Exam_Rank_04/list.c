/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:13:18 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 22:33:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	cmd_add_av(t_cmd *cmd, char *av)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(*tmp) * (cmd->len + 2));
	if (!tmp)
		fatal();
	i = -1;
	while (++i < cmd->len)
		tmp[i] = cmd->av[i];
	if (cmd->len > 0)
		free(cmd->av);
	cmd->av = tmp;
	cmd->av[i++] = ft_strdup(av);
	cmd->av[i] = 0;
	cmd->len++;
	return (EXIT_SUCCESS);
}

int	cmd_add_back(t_cmd **list, char *av)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(*new));
	if (!new)
		fatal();
	new->av = NULL;
	new->len = 0;
	new->type = T_END;
	new->prev = NULL;
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->prev = *list;
	}
	*list = new; // not sure
	return (cmd_add_av(new, av));
}

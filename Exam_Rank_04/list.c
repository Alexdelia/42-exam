/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:13:18 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 22:26:21 by adelille         ###   ########.fr       */
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
		tmp[i] = cmd->av[1];
	if (cmd->len > 0)
		free(cmd->av);
	cmd->av = tmp;
	cmd->av[i++] = ft_strdup(av);
	cmd->av[i] = 0;
	cmd->len++;
	return (EXIT_SUCCESS);
}

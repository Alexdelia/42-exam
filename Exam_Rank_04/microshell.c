/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 22:28:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	parse(t_cmd **list, char *av)
{
	int	b;

	b = FALSE;
	if (strcmp(";", av) == 0)
		b = TRUE;
	if (b && !*list)
		return (0);
	else if (!b && (!*list || (*list)->type != T_END))
		return (cmd_add_back(list, av));
	else if (strcmp("|", av) == 0)
		(*list)->type = T_PIPE;
	else if (b)
		(*list)->type = T_BREAK;
	else
		return (cmd_add_av(*list, av));
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_cmd	*list;
	int		ret;
	int		i;

	ret = EXIT_SUCCESS;
	list = NULL;
	i = 0;
	while (++i < ac)
		parse(&list, av[i]);
	if (list)
		ret = exec_list(&list, env);
	cmd_clear(&list);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 15:48:24 by adelille         ###   ########.fr       */
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
	else if (!b && (!*list || (*list)->type != TYPE_END))
		return (cmd_addback(list, av));
	else if (strcmp("|", av) == 0)
		(*list)->type = TYPE_PIPE;
	else if (b)
		(*list)->type = TYPE_BREAK;
	else
		return (cmd_addfront(list, av));
	return (0);
}

int	main(int ac, char **av, char *env)
{
	t_cmd	*list;
	int		ret;
	int		i;

	ret = EXIT_SUCCESS;
	list = NULL;
	i = 1;
	while (i < ac)
	{
		parse(&list, av[i]);
		i++;
	}
	if (list)
		ret = exec_list(&list, env);
	cmd_clear(&list);
	return (ret);
}

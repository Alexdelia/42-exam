/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 15:35:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	parse(t_cmd **c, char *av)
{
	int	b;

	b = FALSE;
	if (strcmp(";", av) == 0)
		b = TRUE;
	if (b && !*c)
		return (0);
	else if (!b && (!*c || (*c)->type != TYPE_END))
		return (cmd_addback(c, av));
	else if (strcmp("|", av) == 0)
		(*c)->type = TYPE_PIPE;
	else if (b)
		(*c)->type = TYPE_BREAK;
	else
		return (cmd_addfront(c, av));
	return (0);
}

int	main(int ac, char **av, char *env)
{
	t_cmd	*cmd;
	int		ret;
	int		i;

	ret = EXIT_SICCESS;
	cmd = NULL;
	i = 1;
	while (i < ac)
	{
		parse(&cmd, av[i]);
		i++;
	}
	if (cmd)
		ret = exe(&cmd, env); // free in here
	return (ret);
}

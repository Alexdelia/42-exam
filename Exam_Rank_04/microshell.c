/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:11:28 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 15:48:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int ac, char **av, char **env)
{
	int	i;

	i = 0;
	// init val

	while (av[i] && av[i + 1]) // could use ac
	{
		// move av
		// calc len of arg

		if (strcmp(av[0], "cd") == 0)
			exec_cd(av);
		else if (/* ; */)
		{

		}
		else if (/* | */)
		{

		}
	}
	// close fd/pipe
	return (0);
}

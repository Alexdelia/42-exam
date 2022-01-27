/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:09:47 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 15:37:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_pser(const char *str)
{
	return (write(STDERR, str, ft_strlen(str)));
}

/*int	error(const char *text, const int ret)
{
	if (text)
		write(STDERR, text, ft_strlen(text));
	return (ret);
}

void	fatal(void)
{
	exit(error("error: fatal\n", EXIT_FAILURE));
}*/

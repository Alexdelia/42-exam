/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:09:47 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 21:06:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

ssize_t	ft_pser(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (write(STDERR, str, i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:43:08 by adelille          #+#    #+#             */
/*   Updated: 2021/10/29 21:03:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *, ...);

int	main(void)
{
	printf("M=%d\tO=%d\n\n", ft_printf("yes %s%d%x hello\n", "OUI", 42, 42), printf("yes %s%d%x hello\n", "OUI", 42, 42));
	printf("M=%d\tO=%d\n\n", ft_printf("yes %s %d %x hello\n", "", -42, -42), printf("yes %s %d %x hello\n", "", -42, -42));
	printf("M=%d\tO=%d\n\n", ft_printf("%s %d %x\n", "\0", 0, 0), printf("%s %d %x\n", "\0", 0, 0));
	printf("M=%d\tO=%d\n\n", ft_printf("%s %d %x\n", NULL, 260, 260), printf("%s %d %x\n", NULL, 260, 260));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 08:35:58 by adelille          #+#    #+#             */
/*   Updated: 2021/03/02 12:51:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// all of this code is only for exam, don't reproduce that at home

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_flags
{
	int		w;
	int		precis;
	int		count;
	int		i;
}				t_flags;

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_nbrlen(long long n, int divider)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= divider;
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putnbr_base(long long n, char *base, int divider)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-n, base, divider);
		return ;
	}
	if (n > divider - 1)
		ft_putnbr_base(n / divider, base, divider);
	ft_putchar(base[n % divider]);
}

void	parse(char *str, t_flags *flags)
{
	flags->w = -1;
	flags->precis = -1;
	
	return ;
}

int		ft_printf(char *str, ...)
{
	int		count;
	va_list	value;
	t_flags	flags;

	va_start(value, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = parse((char*)str, &flags);
			if (flags.type == 's')
				count += convert_s(value, &flags);
			else if (flags.type == 'd')
				count += convert_d(value, &flags);
			else if (flags.type == 'x')
				count += convert_x(value, &flags);
			else
				return (-1);
		}
		else
		{
			ft_putchar(*str++);
			count++;
		}
	}
	va_end(value);
	return (count);
}

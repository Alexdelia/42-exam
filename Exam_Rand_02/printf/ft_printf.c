/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 08:35:58 by adelille          #+#    #+#             */
/*   Updated: 2021/03/01 14:29:31 by adelille         ###   ########.fr       */
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
	char	type;
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

char	*ft_strcpy(char *dest, char *src)
{
	char	*d;

	d = dest;
	while (*src)
		*dest++ = *src++;
	dest = '\0';
	return (d);
}

int		ft_atoi_skip(char **s)
{
	long	n;

	n = 0;
	while (**s >= '0' && **s <= '9')
	{
		n *= 10;
		n += **s - '0';
		(*s)++;
	}
	return ((int)n);
}

int		convert_s(va_list str, t_flags *flags)
{
	char	*tmp;
	int		len;
	// don't pay attention it's just for exam, no need to put on heap or anything
	char	s[400000];
	int		count;

	tmp = va_arg(str, char *);
	if (tmp == NULL)
		ft_strcpy(s, "(null)");
	else
		ft_strcpy(s, tmp);
	len = ft_strlen(s);
	if (flags->w != -1 && flags->precis != -1)
	{
		while (len > flags->precis)
			len--;
		s[len] = 0;
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > len)
			ft_putchar(' ');
		ft_putstr(s);
		return (count);
	}
	else if (flags->w != -1)
	{
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > len)
			ft_putchar (' ');
		ft_putstr(s);
		return (count);
	}
	else if (flags->precis != -1)
	{
		count = flags->precis < len ? flags->precis : len;
		while (len-- > flags->precis)
			;
		s[len + 1] = 0;
		ft_putstr(s);
		return (count);
	}
	else
		ft_putstr(s);
	return (len);
}

int		convert_d(va_list value, t_flags *flags)
{
	long	n;
	int		len;
	int		count;

	n = (long)va_arg(value, int);
	len = ft_nbrlen(n, 10);
	if (flags->w != -1 && flags->precis != -1)
	{
		count = flags->w > len ? flags->w : len;
		while (flags->w > (flags->precis > len ? (n < 0 ? flags->precis + 1 : flags->precis) : len))
		{
			ft_putchar(' ');
			flags->w--;
		}
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
			len--;
		}
		count = count > flags->precis ? count : flags->precis;
		while (flags->precis-- > len)
			ft_putchar('0');
		ft_putnbr_base(n, "0123456789", 10);
		return (count);
	}
	else if (flags->w != -1)
	{
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > len)
			ft_putchar(' ');
		ft_putnbr_base(n, "0123456789", 10);
		return (count);
	}
	else if (flags->precis != -1)
	{
		count = 0;
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
			len--;
			count = 1;
		}
		count += flags->precis > len ? flags->precis : len;
		while (flags->precis-- > len)
			ft_putchar('0');
		ft_putnbr_base(n, "0123456789", 10);
		return (count);
	}
	ft_putnbr_base(n, "0123456789", 10);
	return (len);
}

int		convert_x(va_list value, t_flags *flags)
{
	unsigned int	n;
	int				len;
	int				count;

	n = va_arg(value, unsigned int);
	len = ft_nbrlen(n, 16);
	if (flags->w != -1 && flags->precis != -1)
	{
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > (flags->precis > len ? flags-> precis : len))
			ft_putchar(' ');
		count = count > flags->precis ? count : flags->precis;
		while (flags->precis-- > len)
			ft_putchar('0');
		ft_putnbr_base(n, "0123456789", 16);
		return (count);
	}
	else if (flags->w != -1)
	{
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > len)
			ft_putchar(' ');
		ft_putnbr_base(n, "0123456789", 16);
		return (count);
	}
	else if (flags->precis != -1)
	{
		count = flags->precis > len ? flags->precis : len;
		while (flags->precis-- > len)
			ft_putchar('0');
		ft_putnbr_base(n, "0123456789", 16);
		return (count);
	}
	ft_putnbr_base(n, "0123456789", 16);
	return (len);
}

char	*parse(char *str, t_flags *flags)
{
	flags->w = -1;
	flags->precis = -1;
	if (*str >= '0' && *str <= '9')
		flags->w = ft_atoi_skip(&str);
	if (*str == '.')
		str++;
	if (*str >= '0' && *str <= '9')
		flags->precis = ft_atoi_skip(&str);
	flags->type = *str++;
	return (str);
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

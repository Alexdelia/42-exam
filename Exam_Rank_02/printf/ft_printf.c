/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:18:41 by adelille          #+#    #+#             */
/*   Updated: 2025/03/03 20:03:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbrlen(int n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_xlen(unsigned int x, int base)
{
	int	i;

	i = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= base;
		i++;
	}
	return (i);
}

int	ft_pc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_ps(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_pn(int n, char *base, int base_len)
{
	char	buffer[10000];
	int		i;

	if (n == 0)
		return (ft_pc('0'));
	if (n == -2147483648)
		return (ft_ps("-2147483648"));
	i = ft_nbrlen(n, base_len);
	if (n < 0 && base_len == 10)
	{
		buffer[0] = '-';
		n = -n;
	}
	buffer[i] = '\0';
	i--;
	while (n > 0)
	{
		buffer[i] = base[n % base_len];
		n /= base_len;
		i--;
	}
	return (ft_ps(buffer));
}

int	ft_px(unsigned int x, char *base, int base_len)
{
	char	buffer[10000];
	int		i;

	if (x == 0)
		return (ft_pc('0'));
	i = ft_xlen(x, base_len);
	buffer[i] = '\0';
	i--;
	while (x > 0)
	{
		buffer[i] = base[x % base_len];
		x /= base_len;
		i--;
	}
	return (ft_ps(buffer));
}

int	ft_convert_s(char *str)
{
	if (!str)
		return (ft_ps("(null)"));
	return (ft_ps(str));
}

int	ft_convert_d(int n)
{
	return (ft_pn(n, "0123456789", 10));
}

int	ft_convert_x(unsigned int x)
{
	return (ft_px(x, "0123456789abcdef", 16));
}

int	ft_convert(va_list arg, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i])
	{
		if (format[i] == 's')
			len = ft_convert_s(va_arg(arg, char *));
		else if (format[i] == 'd')
			len = ft_convert_d(va_arg(arg, int));
		else if (format[i] == 'x')
			len = ft_convert_x(va_arg(arg, unsigned int));
		else
		{
			ft_pc('%');
			ft_pc(format[i]);
			return (2);
		}
	}
	else
		return (ft_pc('%'));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_convert(arg, format, i);
		}
		else
			len += ft_pc(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

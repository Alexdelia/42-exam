/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:18:41 by adelille          #+#    #+#             */
/*   Updated: 2021/09/13 16:54:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

typedef struct s_flags
{
	int		w;
	int		precis;
	char	type;
}			t_flags;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_atoi_skip(char **str)
{
	long n;

	n = 0;
	while (**str && **str >= '0' && **str <= '9')
	{
		n = n * 10 + (**str - '0');
		(*str)++;
	}
	return ((int)n);
}

int		ft_nbrlen(long long n, int base)
{
	int	i;

	if (n < 0)
		n = -n;
	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa(char *s, int n)
{
	int		len;

	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	len = ft_nbrlen(n, 10) - 1;
	if (n < 0)
	{
		s[0] = '-';
		len++;
	}
	s[len] = '\0';
	len--;
	while (n > 0)
	{
		s[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (s);
}

int	ft_convert_s(va_list str, t_flags *flags)
{
	int		len;
	int		count;
	char	s[400000];
	char	*tmp;

	tmp = va_arg(str, char *);
	if (tmp == NULL)
		ft_strcpy(s, "(null)"); // MIGHT BE FALSE
	else
		ft_strcpy(s, tmp);
	len = ft_strlen(s);
	if (flags->w != -1 && flags->precis != -1)
	{
		while (len > flags->precis)
			len--;
		s[len + 1] = 0;
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > len)
			ft_putchar(' ');
		ft_putstr(s);
		return (count);
	}
	else if (flags->w != -1)
	{
		count = (flags->w > len ? flags->w : len);
		while (flags->w-- > len)
			ft_putchar(' ');
		ft_putstr(s);
		return (count);
	}
	else if (flags->precis != -1)
	{
		count = (flags->precis < len ? flags->precis : len);
		while (len > flags->precis)
			len--;
		s[len + 1] = 0;
		ft_putstr(s);
		return (count);
	}
	else
		ft_putstr(s);
	return (len);
}

int	ft_convert_fdx(char *s, t_flags *flags)
{
	int		len;
	int		count;

	len = ft_strlen(s);
	if (flags->w != -1 && flags->precis != -1)
	{
		count = flags->w > len ? flags->w : len;
		while (flags->w-- > len)
			ft_putchar(' ');
		while (flags->precis-- > len)
			ft_putchar('0');
		ft_putstr(s);
		return (count);
	}
	else if (flags->w != -1)
	{
		count = (flags->w > len ? flags->w : len);
		while (flags->w-- > len)
			ft_putchar(' ');
		ft_putstr(s);
		return (count);
	}
	else if (flags->precis != -1)
	{
		count = (flags->precis > len ? flags->precis : len);
		while (flags->precis-- > len)
			ft_putchar('0');
		ft_putstr(s);
		return (count);
	}
	else
		ft_putstr(s);
	return (len);
}

int	ft_convert_d(va_list val, t_flags *flags)
{
	char	s[400000];
	int		n;

	n = va_arg(val, int);
	return (ft_convert_fdx(ft_itoa(s, n), flags));
}

/*int	ft_convert_x(va_list val, t_flags *flags)
{
	unsigned int	n;

	n = va_arg(val, unsigned int);
	return (ft_convert_dfx(ft_xtoa(n), flags);
}*/

char	*ft_parse(char *str, t_flags *flags)
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

int	ft_printf(char *str, ...)
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
			// parse w, ., precis
			str = ft_parse(str, &flags);
			if (flags.type == 's')
				count += ft_convert_s(value, &flags);
			else if (flags.type == 'd')
				count += ft_convert_d(value, &flags);
			/*else if (flags.type == 'x')
				count += ft_convert_x(value, &flags);*/
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

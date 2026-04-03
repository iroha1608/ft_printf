/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsato <nsato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:01:13 by nsato             #+#    #+#             */
/*   Updated: 2025/11/28 13:47:07 by nsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	return ((int)len);
}

int	ft_putnbr(unsigned long long n, char format)
{
	char			*base;
	int				count;
	int				ret;
	long long		len;

	count = 0;
	len = ft_putbase(format, &base);
	if ((format == 'd' || format == 'i') && (long long)n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count ++;
		n = -n;
	}
	if ((unsigned long long)len <= n)
	{
		ret = ft_putnbr(n / len, format);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar(base[n % len]) == -1)
		return (-1);
	count ++;
	return (count);
}

int	ft_putptr_hex(void *str, char format)
{
	int					count;
	int					ret;
	unsigned long long	ptr;

	if (!str)
		return (ft_putstr("(nil)"));
	ptr = (unsigned long long)str;
	count = 0;
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_putnbr(ptr, format);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

long long	ft_putbase(char format, char **base)
{
	long long	len;

	if (format == 'X' || format == 'x' || format == 'p')
	{
		if (format == 'X')
			*base = "0123456789ABCDEF";
		else
			*base = "0123456789abcdef";
		len = 16;
	}
	else
	{
		*base = "0123456789";
		len = 10;
	}
	return (len);
}

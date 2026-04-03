/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsato <nsato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:39:15 by nsato             #+#    #+#             */
/*   Updated: 2025/11/27 19:23:07 by nsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	validate_format(va_list ap, const char *format, size_t *i)
{
	int		count;

	if (format[*i] == '%')
	{
		(*i)++;
		if (format[*i] == '\0')
			return (-1);
		count = check_format(ap, format[*i]);
	}
	else
		count = ft_putchar(format[*i]);
	return (count);
}

int	check_format(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr((unsigned long long)va_arg(ap, int), format);
	else if (format == 'u' || format == 'x' || format == 'X')
		count = ft_putnbr((unsigned long long)va_arg(ap, unsigned int), format);
	else if (format == 'p')
		count = ft_putptr_hex(va_arg(ap, void *), format);
	else if (format == '%')
		count = ft_putchar('%');
	else
	{
		if (ft_putchar('%') == -1 || ft_putchar(format) == -1)
			return (-1);
		return (2);
	}
	return (count);
}

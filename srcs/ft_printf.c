/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsato <nsato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:49:08 by nsato             #+#    #+#             */
/*   Updated: 2025/11/27 19:01:29 by nsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		ret = validate_format(ap, format, &i);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += ret;
		i ++;
	}
	va_end(ap);
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

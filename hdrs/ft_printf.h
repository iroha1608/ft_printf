/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsato <nsato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:49:47 by nsato             #+#    #+#             */
/*   Updated: 2025/11/27 19:14:28 by nsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* Main Function */
int				ft_printf(const char *format, ...);

/* Check Functions */
int				check_format(va_list ap, const char format);
int				validate_format(va_list ap, const char *format, size_t *i);

/* Put Functions */
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_putnbr(unsigned long long n, char format);
int				ft_putptr_hex(void *str, char format);
long long		ft_putbase(char format, char **base);

/* Libft */
size_t			ft_strlen(const char *s);

#endif

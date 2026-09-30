/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .ft_printf_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsato <nsato@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:50:02 by nsato             #+#    #+#             */
/*   Updated: 2025/12/01 18:40:40 by nsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int			ret_mine;
	int			ret_orig;

	/* Test1 char */
	ft_printf("Test1:	Character\n");
	write(1, "Test: ", 6);
	ret_mine = ft_printf("[%c]\n", 'A');
	write(1, "Orig: ", 6);
	ret_orig = printf("[%c]\n", 'A');

	/* Test2 return */
	ft_printf("\nTest2:	Return Value\n");
	ft_printf("Return:	Mine:%d, Orig:%d\n", ret_mine, ret_orig);

	/* Test3 char * */
	ft_printf("\nTest3:	String\n");
	char	*str = NULL;
	ft_printf("Test String:	%s\n", "Hello 42");
	ft_printf("Test Empty:	%s\n", "");
	ft_printf("Test NULL:	%s\n", str);
	printf("Orig String:	%s\n", "Hello 42");
	printf("Orig Empty:	%s\n", "");
	printf("Orig NULL:	%s\n", str);

	/* Test4 int */
	ft_printf("\nTest4:	Integer\n");
	ft_printf("Test Integer:	%d\n", 10000);
	ft_printf("Test INT_MIN:	%d\n", INT_MIN);
	ft_printf("Test INT_MAX:	%d\n", INT_MAX);
	printf("Orig Integer:	%d\n", 10000);
	printf("Orig INT_MIN:	%d\n", INT_MIN);
	printf("Orig INT_MAX:	%d\n", INT_MAX);

	/* Test5 %i */
	ft_printf("\nTest5:	'i'\n");
	ft_printf("Test Integer:	%i\n", 10000);
	ft_printf("Test INT_MIN:	%i\n", INT_MIN);
	ft_printf("Test INT_MAX:	%i\n", INT_MAX);
	printf("Orig Integer:	%i\n", 10000);
	printf("Orig INT_MIN:	%i\n", INT_MIN);
	printf("Orig INT_MAX:	%i\n", INT_MAX);

	/* Test6 unsigned int */
	ft_printf("\nTest6:	Unsigned Integer\n");
	ft_printf("Test Integer:	%u\n", 10000);
	ft_printf("Test INT_MAX:	%u\n", INT_MAX);
	ft_printf("Test UINT_MAX:	%u\n", UINT_MAX);
	printf("Orig Integer:	%u\n", 10000);
	printf("Orig INT_MAX:	%u\n", INT_MAX);
	printf("Orig UINT_MAX:	%u\n", UINT_MAX);

	/* Test7 hex small */
	ft_printf("\nTest7:	Hexadecimal Small\n");
	ft_printf("Test Integer:	%x\n", 10000);
	ft_printf("Test INT_MAX:	%x\n", INT_MAX);
	ft_printf("Test UINT_MAX:	%x\n", UINT_MAX);
	printf("Orig Integer:	%x\n", 10000);
	printf("Orig INT_MAX:	%x\n", INT_MAX);
	printf("Orig UINT_MAX:	%x\n", UINT_MAX);
	
	/* Test8 hex big */
	ft_printf("\nTest8:	Hexadecimal Big\n");
	ft_printf("Test Integer:	%X\n", 10000);
	ft_printf("Test INT_MAX:	%X\n", INT_MAX);
	ft_printf("Test UINT_MAX:	%X\n", UINT_MAX);
	printf("Orig Integer:	%X\n", 10000);
	printf("Orig INT_MAX:	%X\n", INT_MAX);
	printf("Orig UINT_MAX:	%X\n", UINT_MAX);

	/* Test9 Hexadecimal void ptr */
	ft_printf("\nTest9:	Hexadecimal void ptr\n");
	void	*ptr = NULL;
	ft_printf("Test Integer:	%p\n", "10000");
	ft_printf("Test INT_MAX:	%p\n", "INT_MAX");
	ft_printf("Test UINT_MAX:	%p\n", "UINT_MAX");
	ft_printf("Test Empty:	%p\n", "");
	ft_printf("Test NULL:	%p\n", ptr);
	printf("Orig Integer:	%p\n", "10000");
	printf("Orig INT_MAX:	%p\n", "INT_MAX");
	printf("Orig UINT_MAX:	%p\n", "UINT_MAX");
	printf("Orig Empty:	%p\n", "");
	printf("Orig NULL:	%p\n", ptr);
	
	/* Test10 % */
	ft_printf("\nTest10:	%\n");
	printf("%d\n", ft_printf("Test:	%%です\n"));
	printf("%d\n", ft_printf("Test:	%です\n"));
	printf("%d\n", ft_printf("Test:	abcd%"));
	printf("%d\n", ft_printf("Test:	%s%d%cです\n", "1234", 5, '6'));
	printf("%d\n", printf("Orig:	%%です\n"));
	printf("%d\n", printf("Orig:	%です\n"));
	printf("%d\n", printf("Orig:	abcd%"));
	printf("%d\n", printf("Orig:	%s%d%cです\n", "1234", 5, '6'));

	/* Test11 Failed to Write */
	ft_printf("\nTest11:	Failed to write\n");
	ret_mine = ft_printf("%s", "before\n");
	ret_orig = printf("%s", "before\n");
	printf("Test=%d, Orig=%d\n", ret_mine, ret_orig);
	close(1);
	ret_mine = ft_printf("%s", "after\n");
	ret_orig = printf("%s", "after\n");
	fflush(stdout);
	dprintf(2, "Test=%d, Orig=%d\n", ret_mine, ret_orig);
	return (0);
}

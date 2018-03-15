/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/15 16:11:26 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void	init_tools(t_utils *format)
{
	format->minus = false;
	format->plus = false;
	format->space = false;
	format->hash = false;
	format->zero = false;
	format->cha_r = 0;
	format->i_nt = 0;
	format->width = -1;
	format->precision = 0;
	format->modifier = 0;
	format->buf = 0;
	format->len = 0;
}

void	parse_form(char *str, int *x, va_list input, t_utils *i)
{
	print_prefix(str, *x, i);
	if (str[*x] == '%')
		*x += 1;
	while (str[*x] && (str[*x] == '-' || str[*x] == '+' || str[*x] == ' ' ||
		str[*x] == '#' || ft_isdigit(str[*x]) == 1 || str[*x] == '.' ||
		str[*x] == '*' || str[*x] == 'h' || str[*x] == 'l' ||
		str[*x] == 'j' || str[*x] == 'z' || str[*x] == 'q'))
	{
		set_flags(str, x, i);
		set_mods(str, x, i);
		set_width(str, x, i);
		set_prec(str, x, i);
	}
	set_conv(str, x, input, i);
	print_postfix(str, *x, i);
}

int	ft_printf(char const *restrict format, ...)
{
	char 		*ret;
	int			x;
	va_list		input;
	t_utils		strut;

	x = 0;
	ret = NULL;
	va_start(input, format);
	while (format[x])
	{
		if (format[x] == '%')
		{
			init_tools(&strut);
			parse_form((char *)format, &x, input, &strut);
		}
		x++;
	}
	va_end(input);
	return (strut.len);
}

int	main(void)
{
	// char *str;

	// str = "Goodbye Cruel World!";
	// printf("S1:[%s]\n", str);
	// ft_printf("S2:[%s]\n", str);
	// printf("S1:[%10s]\n", str);
	// ft_printf("S2:[%10s]\n", str);
	// printf("S1:[%-10s]\n", str);
	// ft_printf("S2:[%-10s]\n", str);
	// printf("S1:[%10.1s]\n", str);
	// ft_printf("S2:[%10.1s]\n", str);
	// printf("S1:[%10.6s]\n", str);
	// ft_printf("S2:[%10.6s]\n", str);
	// printf("S1:[%s]\n", "");
	// ft_printf("S2:[%s]\n", "");
    // printf("width 10:          [%10s]\n", "Hello");
    // ft_printf("width 10:           [%10s]\n", "Hello");
    // printf("minus and width 10:        [%-10s]\n", "Hello");
    // ft_printf("minus and width 10:     [%-10s]\n", "Hello");
    // printf("precyzja 1:            [%.1s]\n", "Hello");
    // ft_printf("precyzja 1:			[%.1s]\n", "Hello");
    // ft_printf("width 10 prec 1:		[%10.1s]\n", "Hello");
	// printf("width 10 prec 1:		[%10.1s]\n", "Hello");
    // printf("width 10 prec 6:		[%10.6s]\n", "Hello");
    // ft_printf("width 10 prec 6:        [%10.6s]\n", "Hello");
    // printf("empty:             [%s]\n", "");
    // ft_printf("empty:              [%s]\n", "");
    // printf("null:              [%s]\n", NULL);
    // ft_printf("null:               [%s]\n", NULL);
    // printf("[%s]\n", "100% des gens qui parlent à Ly adorent Ly.");
    // ft_printf("[%s]\n", "100% des gens qui parlent à Ly adorent Ly.");
    // printf("width 5 prec . = [%5.s]\n", "supfag");
	// ft_printf("width 5 prec . = [%5.s]\n", "supfag");

	// // ---------------------------------------------

	// printf("[Printf:%d]\n", 10);
	// ft_printf("[Dopeee:%d]\n", 10);
	// printf("[Printf:%5d]\n", 10);
	// ft_printf("[Dopeee:%5d]\n", 10);
	// printf("[Printf:%5.1d]\n", 10);
	// ft_printf("[Dopeee:%5.1d]\n", 10);
	// printf("[Printf:%.1d]\n", 10);
	// ft_printf("[Dopeee:%.1d]\n", 10);
	// printf("[Printf:%.1d]\n", 123456);
	// ft_printf("[Dopeee:%.1d]\n", 123456);
	// printf("[Printf:%10.1d]\n", 123456);
	// ft_printf("[Dopeee:%10.1d]\n", 123456);
	// printf("[Printf:%5.1d]\n", 123456);
	// ft_printf("[Dopeee:%5.1d]\n", 123456);
	// ft_printf("[Dopeee:%0.15d]\n", 123456);
	// printf("[Printf:%0.15d]\n", 123456);
	// printf("[Printf:%-5d]\n", 10);
	// ft_printf("[Dopeee:%-5d]\n", 10);
	// printf("[Printf:%-5.1d]\n", 10);
	// ft_printf("[Dopeee:%-5.1d]\n", 10);
	// printf("[Printf:%.1d]\n", 10);
	// ft_printf("[Dopeee:%.1d]\n", 10);
	// printf("[Printf:%-10.1d]\n", 123456);
	// ft_printf("[Dopeee:%-10.1d]\n", 123456);

	// -----------------------------------------------

	// printf("' ':	[% d]\n", -12);
    // ft_printf("' ':	[% d]\n", -12);
	// printf("10.6:	[% 10.6d]\n", 12);
    // ft_printf("10.6:	[% 10.6d]\n", 12);
	// printf("0 10.6:	[%0 10.6d]\n", 12);
    // ft_printf("0 10.6:	[%0 10.6d]\n", 12);
	// printf("-+10.5:	[%-+10.5d]\n", -12);
    // ft_printf("-+10.5:	[%-+10.5d]\n", -12);
	// printf("zero:	[%0i]\n", 12);
    // ft_printf("zero:	[%0i]\n", 12);
	// printf("width 10:	[%10i]\n", 12);
    // ft_printf("width 10:	[%10i]\n", 12);
    // printf("minus and width 10:	[%-10i]\n", 12);
	// ft_printf("minus and width 10:	[%-10i]\n", 12);
    // printf("precyzja 1:	[%.1i]\n", 12);
	// ft_printf("precyzja 1:	[%.1i]\n", 12);
    // printf("width 10 prec 6:	[%10.6i]\n", 12);
	// ft_printf("width 10 prec 6:	[%10.6i]\n", 12);
	// printf("W 10 P 1:	[%10.1i]\n", 12);
	// ft_printf("W 10 P 1:	[%10.1i]\n", 12);
    // printf("- width 10 prec 6:	[%-10.6i]\n", 12);
	// ft_printf("- width 10 prec 6:	[%-10.6i]\n", 12);
    // printf("0 width 4 prec 3:	[%04.3d]\n", -1);
	// ft_printf("0 width 4 prec 3:	[%04.3d]\n", -1);
    // printf("+ width 10 prec 5:	[%+10.5d]\n", 25);
	// ft_printf("+ width 10 prec 5:	[%+10.5d]\n", 25);
    // printf("width 10 prec 5:	[%+10.5d]\n", -25);
	// ft_printf("width 10 prec 5:	[%+10.5d]\n", -25);
    // printf("0 width 3 prec 2:	[%03.2d]\n", -1);
	// ft_printf("0 width 3 prec 2:	[%03.2d]\n", -1);
    // printf("prec 10:	[%.10d]\n", -12);
	// ft_printf("prec 10:	[%.10d]\n", -12);
    // printf("width 5 prec .:	[%5.d]\n", 0);
	// ft_printf("width 5 prec .:	[%5.d]\n", 0);
    // printf("42:	[%d]\n", 42);
	// ft_printf("42:	[%d]\n", 42);
    // printf("t: 0 width 4:	[% 04d]\n", 1);
	// ft_printf("m: 0 width 4:	[% 04d]\n", 1);
    // printf("width 4 prec.:	[%4.d]\n", 0);
	// ft_printf("width 4 prec.:	[%4.d]\n", 0);
    // printf("t: 0 width 10:	[%010d]\n", 0);
	// ft_printf("m: 0 width 10:	[%010d]\n", 0);
    // printf("0 width 5:	[%05d]\n", -42);
	// ft_printf("0 width 5:	[%05d]\n", -42);
	// printf("- width 5:	[%-5d]\n", -42);
	// ft_printf("- width 5:	[%-5d]\n", -42);
    // printf("+ width 10 prec 5:	[%+10.5d]\n", 4242);
	// ft_printf("+ width 10 prec 5:	[%+10.5d]\n", 4242);
    // printf("0 width 3 prec 2:	[%03.2d]\n", 0);
	// ft_printf("0 width 3 prec 2:	[%03.2d]\n", 0);
    // printf("0 width 3 prec 2:	[%03.2d]\n", -1);
	// ft_printf("0 width 3 prec 2:	[%03.2d]\n", -1);

	//---------------------------------------------------

	// printf("[%c]\n", 'H');
	// ft_printf("[%c]\n", 'H');

	// printf("Width 2:	[%2c]\n", 'H');
	// ft_printf("Width 2:	[%2c]\n", 'H');

	// --------------------------------------------------
// printf("%lu\n", 4294967295);
// ft_printf("%lu\n", 4294967295);
// printf("%lu\n", 4294967296);
// ft_printf("%lu\n", 4294967296);
// printf("%lu\n", 9223372036854775807);
// ft_printf("%lu\n", 9223372036854775807);
// printf("%llu\n", 9223372036854775808);
// ft_printf("%llu\n", 9223372036854775808);
// ft_printf("# prec .:			[%#.u]\n", 0);
// printf("# prec .:			[%#.u]\n", 0);
// ft_printf("# prec 0:			[%#.0u]\n", 0);
// printf("# prec 0:			[%#.0u]\n", 0);
// ft_printf("prec .:				[%.u]\n", 0);
// printf("prec .:				[%.u]\n", 0);
// ft_printf("prec 0:				[%.0u]\n", 0);
// printf("prec 0:				[%.0u]\n", 0);
// ft_printf("[%05.2u]\n", 1);
// printf("[%05.2u]\n", 1);
// ft_printf("[%05.u]\n", 1);
// printf("[%05.u]\n", 1);
// ft_printf("[%05.1u]\n", 1);
// printf("[%05.1u]\n", 1);
// ft_printf("[%05.0u]\n", 1);
// printf("[%05.0u]\n", 1);
// ft_printf("%x\n", 21);
// printf("%x\n", 21);
// printf("\n switch \n\n");
// printf("%lu\n", 9223372036854775807);
// ft_printf("%lu\n", 9223372036854775807);
// printf("%llu\n", 18446744073709551615);
// ft_printf("%llu\n", 18446744073709551615);

// // ------------------------- x, X------------------------

	printf("t: normal:			[%x]\n", 1244);
	ft_printf("m: normal:			[%x]\n\n", 1244);
	printf("zero:				[%0x]\n", 1244);
	ft_printf("zero:				[%0x]\n\n", 1244);
	printf("width 10:			[%10x]\n", 1244);
	ft_printf("width 10:			[%10x]\n\n", 1244);
	printf("minus and width 10:		[%-10x]\n", 1244);
	ft_printf("minus and width 10:		[%-10x]\n\n", 1244);
	printf("hash:				[%#x]\n", 1244);
	ft_printf("hash:				[%#x]\n\n", 1244);
	printf("precyzja 1:			[%.1x]\n", 1244);
	ft_printf("precyzja 1:			[%.1x]\n\n", 1244);
	printf("width 10 prec 6:		[%010.6x]\n", 1244);
	ft_printf("width 10 prec 6:		[%010.6x]\n\n", 1244);
	printf("# 0 width 10 prec 6:		[%#010.6x]\n", 1244);
	ft_printf("# 0 width 10 prec 6:		[%#010.6x]\n\n", 1244);
	printf("# width 10 prec 6:		[%#10.6x]\n", 1244);
	ft_printf("# width 10 prec 6:		[%#10.6x]\n\n", 1244);
	printf("ble ble:			[%20.5x]\n", 1245455464);
	ft_printf("ble ble:			[%20.5x]\n\n", 1245455464);
	printf("# [%#x]\n", 1244);
	ft_printf("# [%#x]\n\n", 1244);
	printf("# and width 10 [%#10x]\n", 1244);
	ft_printf("# and width 10 [%#10x]\n\n", 1244);
	printf("# prec 10[%#.10x]\n", 1244);
	ft_printf("# prec 10[%#.10x]\n\n", 1244);
	printf("prec .:				[%.x]\n", 0);
	ft_printf("prec .:				[%.x]\n\n", 0);
	printf("lx:				[%lx]\n", 4294967296);
	ft_printf("lx:				[%lx]\n\n", 4294967296);
	printf("x:				[%x]\n", 0);
	ft_printf("x:				[%x]\n\n", 0);
	printf("X:				[%X]\n", 0);
	ft_printf("X:				[%X]\n\n", 0);	
	printf("#x:				[%#x]\n", 0);
	ft_printf("#x:				[%#x]\n\n", 0);
	printf("#0 width 8:			[%#08x]\n", 42);
	ft_printf("#0 width 8:			[%#08x]\n\n", 42);
	printf("# width 8:			[%#8x]\n", 42);
	ft_printf("# width 8:			[%#8x]\n\n", 42);   
	printf("# prec .:			[%#.x]\n", 0);
	ft_printf("# prec .:			[%#.x]\n\n", 0);
	// printf("width 5 prec .:			[%5.x]\n", 0);
	ft_printf("width 5 prec .:			[%5.x]\n\n", 0);
	printf("width 5 prec 0:			[%5.0x]\n", 0);
	ft_printf("width 5 prec 0:			[%5.0x]\n\n", 0);
	ft_printf("# prec .:			[%#.x]\n", 0);
	printf("# prec .:			[%#.x]\n\n", 0);
	ft_printf("# prec 0:			[%#.0x]\n", 0);
	printf("# prec 0:			[%#.0x]\n\n", 0);
	ft_printf("prec .:				[%.x]\n", 0);
	printf("prec .:				[%.x]\n\n", 0);
	ft_printf("prec 0:				[%.0x]\n", 0);
	printf("prec 0:				[%.0x]\n\n", 0);
	printf("t: normal:			[%X]\n", 1244);
	ft_printf("m: normal:			[%X]\n\n", 1244);
	printf("zero:				[%0X]\n", 1244);
	ft_printf("zero:				[%0X]\n\n", 1244);
	printf("width 10:			[%10X]\n", 1244);
	ft_printf("width 10:			[%10X]\n\n", 1244);
	printf("minus and width 10:		[%-10X]\n", 1244);
	ft_printf("minus and width 10:		[%-10X]\n\n", 1244);
	printf("hash:				[%#X]\n", 1244);
	ft_printf("hash:				[%#X]\n\n", 1244);
	printf("precyzja 1:			[%.1X]\n", 1244);
	ft_printf("precyzja 1:			[%.1X]\n\n", 1244);
	printf("width 10 prec 6:		[%010.6X]\n", 1244);
	ft_printf("width 10 prec 6:		[%010.6X]\n\n", 1244);
	printf("# 0 width 10 prec 6:		[%#010.6X]\n", 1244);
	ft_printf("# 0 width 10 prec 6:		[%#010.6X]\n\n", 1244);
	printf("# width 10 prec 6:		[%#10.6X]\n", 1244);
	ft_printf("# width 10 prec 6:		[%#10.6X]\n\n", 1244);
	printf("# [%#X]\n", 1244);
	ft_printf("# [%#X]\n\n", 1244);
	printf("# and width 10 [%#10X]\n", 1244);
	ft_printf("# and width 10 [%#10X]\n", 1244);
	printf("# prec 10[%#.10X]\n", 1244);
	ft_printf("# prec 10[%#.10X]\n", 1244);
	printf("prec .:				[%.X]\n", 0);
	ft_printf("prec .:				[%.X]\n", 0);
	printf("lx:				[%lX]\n", 4294967296);
	ft_printf("lx:				[%lX]\n", 4294967296);
	printf("x:				[%X]\n", 0);
	ft_printf("x:				[%X]\n", 0);
	printf("X:				[%X]\n", 0);
	ft_printf("X:				[%X]\n", 0);
	printf("#x:				[%#X]\n", 0);
	ft_printf("#x:				[%#X]\n", 0);	
	printf("#0 width 8:			[%#08X]\n", 42);
	ft_printf("#0 width 8:			[%#08X]\n", 42);
	printf("# prec .:			[%#.X]\n", 0);
	ft_printf("# prec .:			[%#.X]\n", 0);
	printf("width 5 prec .:			[%5.X]\n", 0);
	ft_printf("width 5 prec .:			[%5.X]\n", 0);
	printf("width 5 prec 0:			[%5.0X]\n", 0);
	ft_printf("width 5 prec 0:			[%5.0X]\n", 0);
	printf("[%2x]\n", 9);
	ft_printf("[%2x]\n", 9);

// // //--------------------------------o, O-----------------------------------
	// unsigned long long nb = 18446744073709551615;
	// ft_printf("normal = [%o]\n", 100);
	// printf("normal = [%o]\n", 100);
	// ft_printf("- width 10 prec 5:		[%-10.5o]\n", 25);
	// printf("- width 10 prec 5:		[%-10.5o]\n", 25);
	// ft_printf("- width 5 prec 10:		[%-5.10o]\n", 25);
	// printf("- width 5 prec 10:		[%-5.10o]\n", 25);
	// ft_printf("hh:				[%hho]\n", 1234);
	// printf("hh:				[%hho]\n", 1234);
	// ft_printf("o:				[%o]\n", 0);
	// printf("o:				[%o]\n", 0);
	// ft_printf("# prec .:			[%#.o]\n", 0);
	// printf("# prec .:			[%#.o]\n", 0);
	// ft_printf("# prec 0:			[%#.0o]\n", 0);
	// printf("# prec 0:			[%#.0o]\n", 0);
	// ft_printf("prec .:				[%.o]\n", 0);
	// printf("prec .:				[%.o]\n", 0);
	// ft_printf("prec 0:				[%.0o]\n", 0);
	// printf("prec 0:				[%.0o]\n", 0);
	// ft_printf("l:				[%lo]\n", 9223372036854775807);
	// printf("l:				[%lo]\n", 9223372036854775807);
	// ft_printf("l:				[%llo]\n", nb);
	// printf("l:				[%llo]\n", nb);
	// ft_printf("z:				[%zo]\n", 0);
	// printf("z:				[%zo]\n", 0);
	// ft_printf("z:				[%zo]\n", 18446744073709551615);
	// printf("z:				[%zo]\n", 18446744073709551615);
	// ft_printf("hh:				[%hhO]\n", 0);
	// printf("hh:				[%hhO]\n", 0);
	// ft_printf("hh:				[%hhO]\n", 65535);
	// printf("hh:				[%hhO]\n", 65535);
	// --------------------------------------------------

	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/27 15:37:13 by mosborne         ###   ########.fr       */
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
	format->i_nt = 0;
	format->width = -1;
	format->precision = 0;
	format->modifier = 0;
	format->buf = 0;
	format->len = 0;
}

void	parse_form(char *str, int *x, va_list input, t_utils *i)
{
	print_prefix(str, *x);
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
	print_postfix(str, *x);
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
	
    printf("- width 10 prec 6:	[%-10.6i]\n", 12);
	ft_printf("- width 10 prec 6:	[%-10.6i]\n", 12);
	
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
	
    printf("width 5 prec .:	[%5.d]\n", 0);
	ft_printf("width 5 prec .:	[%5.d]\n", 0);
	
    // printf("42:	[%d]\n", 42);
	// ft_printf("42:	[%d]\n", 42);
	
    printf("t: 0 width 3:	[% 04d]\n", 1);
	ft_printf("m: 0 width 3:	[% 04d]\n", 1);
	
    printf("width 4 prec.:	[%4.d]\n", 0);
	ft_printf("width 4 prec.:	[%4.d]\n", 0);
	
    printf("t: 0 width 10:	[%010d]\n", 0);
	ft_printf("m: 0 width 10:	[%010d]\n", 0); // BROKEN
	
    // printf("0 width 5:	[%05d]\n", -42);
	// ft_printf("0 width 5:	[%05d]\n", -42);
	
	printf("- width 5:	[%-5d]\n", -42);
	ft_printf("- width 5:	[%-5d]\n", -42); // BROKEN

    // printf("+ width 10 prec 5:	[%+10.5d]\n", 4242);
	// ft_printf("+ width 10 prec 5:	[%+10.5d]\n", 4242);
	
    // printf("0 width 3 prec 2:	[%03.2d]\n", 0);
	// ft_printf("0 width 3 prec 2:	[%03.2d]\n", 0);

    // printf("0 width 3 prec 2:	[%03.2d]\n", -1);
	// ft_printf("0 width 3 prec 2:	[%03.2d]\n", -1);


	return (1);
}

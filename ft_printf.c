/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/19 18:08:58 by mosborne         ###   ########.fr       */
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
	format->width = 0;
	format->precision = 0;
	format->modifier = 0;
	format->str = 0;
	format->len = 0;
}

void	parse_form(char *str, int *x, va_list input, t_utils *i)
{
	print_prefix(str, *x);
	if (str[*x] == '%')
		*x +=1;
	while (str[*x] && (str[*x] == '-' || str[*x] == '0' || str[*x] == '+' ||
	str[*x] == ' ' || str[*x] == '#' || ft_isdigit(str[*x]) == 1 ||
	str[*x] == '.' || str[*x] == '*' || str[*x] == 'h' || str[*x] == 'l' ||
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
	// ---------------------------------------------
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
	
	printf("[Printf:%10.1d]\n", 123456);
	ft_printf("[Dopeee:%10.1d]\n", 123456);
	
	printf("[Printf:%5.1d]\n", 123456);
	ft_printf("[Dopeee:%5.1d]\n", 123456);
	
	ft_printf("[Dopeee:%0.15d]\n", 123456);
	printf("[Printf:%0.15d]\n", 123456);
	
	return (1);
}

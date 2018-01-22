/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/21 19:04:06 by mosborne         ###   ########.fr       */
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

void	parse_form(char *str, int *x, va_list input, t_utils *i, char *ret)
{
	print_prefix(str, *x);
	*x += 1;
	while (str[*x] && (OP(str[*x]) || str[*x] == MOD(str[*x]) || ft_isdigit(str[*x]) != 0 || 
		str[*x] == '.' || str[*x] == '*'))
	{
		set_flags(str, x, i);
		set_mods(str, x, i);
		set_width(str, x, i);
		set_prec(str, x, input, i);
	}
	if (CONV(str[*x]))
		set_conv(str, x, input, i, ret);
}

int	ft_printf(char const *restrict format, ...)
{
	char 		ret[1024];
	static int	x = 0;
	va_list		input;
	t_utils		strut;

	init_tools(&strut);
	va_start(input, format);
	while (format[x])
	{
		if (format[x] == '%')
		{
			parse_form((char *)format, &x, input, &strut, ret);
		}
		x++;
	}
	printf("\n\nminus:%d", strut.minus);
	printf("\nplus:%d", strut.plus);
	printf("\nwidth:%d", strut.width);
	printf("\nprecision:%d", strut.precision);
	va_end(input);
	return (1);
}

int	main(void)
{
	ft_printf("\n%s", "hey");
	printf("\n%-.1s", "hey");
}

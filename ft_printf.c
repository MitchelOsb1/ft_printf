/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/20 13:41:31 by mosborne         ###   ########.fr       */
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
	format->star = false;
	format->dot = 0;
	format->width = 0;
	format->precision = 0;
	format->modifier = 0;
	format->str = 0;
	format->len = 0;
}

char	*parse_form(char *str, int *x, va_list input, t_utils *i)
{
	print_prefix(str, *x);
	*x += 1;
	while (str[*x] && (OP(str[*x]) || str[*x] == MOD(str[*x]) || ft_isdigit(str[*x]) != 0 || 
		str[*x] == '.' || str[*x] == '*'))
	{
		set_flags(str, x, i); // incerment each function so x doesnt need to icnrhere
		set_mods(str, x, i); //
		set_width(str, x, input, i);
		set_prec(str, x, input, i);
	}
	if (str[*x] == CONV(str[*x]))
		set_conv(str, x, input, i);
	return (str);
}

int	ft_printf(char const *restrict format, ...)
{
	char		*ret;
	static int	x = 0;
	va_list		input;
	t_utils		strut;

	init_tools(&strut);
	va_start(input, format);
	while (format[x])
	{
		if (format[x] == '%')
		{
			ret = parse_form((char *)format, &x, input, &strut);
		}
		x++;
	}
	printf("\n\nminus:%d", strut.minus);
	printf("\nprecision:%d", strut.precision);
	printf("\nwidth:%d", strut.width);
	va_end(input);
	return (1);
}

int	main(void)
{
	ft_printf("\n%-.1s", "hey");
	printf("\n%-.1s", "hey");
}

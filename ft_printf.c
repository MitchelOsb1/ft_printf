/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/19 14:38:11 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void	init_tools(t_tools *format)
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

char	*parse_form(char *str, int *x, va_list input, t_tools i)
{
	print_prefix(str, *x);
	x++;
	while (str[*x])
	{
		set_flags(str, x, i); // incerment each function so x doesnt need to icnrement in here
		set_mods(str, x, i); //
		set_width(str, x, input, i);
		set_prec(str, x, input, i);
		x++;
	}
	return (str);
}

int	ft_printf(char const *restrict str, ...)
{
	char		*ret;
	static int	x = 0;
	va_list		input;
	t_tools		format;

	init_tools(&format);
	va_start(input, str);
	while (str[x])
	{
		if (str[x] == '%')
		{
			ret = parse_form((char *)str, &x, input, format);
		}
		x++;
	}
	printf("%s", ret);
	printf("\nprecision:%d", format.minus);
	printf("\nwidth:%d", format.width);
	va_end(input);
	return (1);
}

int	main(void)
{
	ft_printf("\n%-1s", "hey");
	printf("\n%-1s", "hey");
}

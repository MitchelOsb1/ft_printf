/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/11 13:29:23 by mosborne         ###   ########.fr       */
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
}

int	ft_printf(char const *restrict format, ...)
{
	char 		*ret;
	static int	x = 0;
	va_list		input;
	t_utils		strut;

	ret = NULL;
	init_tools(&strut);
	va_start(input, format);
	while (format[x])
	{
		if (format[x] == '%')
		{
			parse_form((char *)format, &x, input, &strut);
		}
		x++;
	}
	va_end(input);
	return (strut.len);
}

int	main(void)
{
	char *str;

	str = "Hellooooo";
	printf("PRINTF:%5s\n", str);
	ft_printf("FT_PRINTF:%5s", str);
}

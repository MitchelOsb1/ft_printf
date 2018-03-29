/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/29 11:32:03 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	format->precision = -1;
	format->modifier = -1;
	format->buf = 0;
	format->len = 0;
	format->count = 0;
}

void	parse_form(char *str, int *x, va_list input, t_utils *i)
{
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
}

int	ft_printf(char const *restrict format, ...)
{
	int	x;
	int y;
	int ret;
	va_list		input;
	t_utils		strut;

	x = 0;
	y = 0;
	ret = 0;
	va_start(input, format);
	init_tools(&strut);
	while (format[x])
	{
		if (format[x] == '%')
		{
			init_tools(&strut);
			print_prefix((char *)format, y, x, &strut);
			parse_form((char *)format, &x, input, &strut);
			ret += strut.count;
			y = x;
		}
		else if (format[x])
			x++;
	}
	print_prefix((char *)format, y, x, &strut);
	if (ret < strut.count)
		ret = strut.count;
	va_end(input);
	printf("[%d]\n", ret);
	return (ret);
}

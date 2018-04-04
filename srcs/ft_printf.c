/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/03 16:24:07 by mosborne         ###   ########.fr       */
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
		str[*x] == '*' || str[*x] == 'h' || str[*x] == 'l' || str[*x] == 'j'
		|| str[*x] == 'z' || str[*x] == 'q' || str[*x] == 'w'))
	{
		set_flags(str, x, i);
		set_mods(str, x, i);
		set_width(str, x, i);
		set_prec(str, x, i);
	}
	set_conv(str, x, input, i);
}

int		init_printf(char *str, va_list input, t_utils *i)
{
	int			x;
	int			ret;
	int			y;

	y = 0;
	x = 0;
	ret = 0;
	while (str[x])
	{
		if (str[x] == '%')
		{
			init_tools(i);
			print_prefix((char *)str, y, x, i);
			parse_form((char *)str, &x, input, i);
			ret += i->count;
			y = x;
		}
		else if (str[x])
			x++;
	}
	print_prefix((char *)str, y, x, i);
	ret = ret + x - y;
	return (ret);
}

int		ft_printf(char const *restrict format, ...)
{
	int			ret;
	va_list		input;
	t_utils		strut;

	ret = 0;
	init_tools(&strut);
	va_start(input, format);
	ret = init_printf((char *)format, input, &strut);
	va_end(input);
	return (ret);
}

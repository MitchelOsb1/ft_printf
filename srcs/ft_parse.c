/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/03 15:16:14 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_flags(char *str, int *x, t_utils *i)
{
	while ((str[*x]) && ((str[*x] == '-') || (str[*x] == '0') || str[*x] == '+'
		|| (str[*x] == ' ') || (str[*x] == '#')))
	{
		if (str[*x] == '-')
			i->minus = true;
		else if (str[*x] == '+')
			i->plus = true;
		else if (str[*x] == ' ' && i->plus == false)
			i->space = true;
		else if (str[*x] == '#')
			i->hash = true;
		else if (str[*x] == '0' && i->minus == false)
			i->zero = true;
		*x += 1;
	}
}

void	set_mods(char *str, int *x, t_utils *i)
{
	while ((str[*x]) && (str[*x] == 'h' || str[*x] == 'l' || str[*x] == 'j' ||
		str[*x] == 'z' || str[*x] == 'q' || str[*x] == 'w'))
	{
		if (str[*x] == 'h')
		{
			if (str[*x + 1] == 'h')
				i->modifier = 1;
			else if (i->modifier != 1)
				i->modifier = 0;
		}
		else if (str[*x] == 'l')
		{
			if (str[*x + 1] == 'l')
				i->modifier = 3;
			else if (i->modifier != 3)
				i->modifier = 2;
		}
		else if (str[*x] == 'j')
			i->modifier = 4;
		else if (str[*x] == 'z')
			i->modifier = 5;
		else if (str[*x] == 'w')
			i->modifier = 6;
		*x += 1;
	}
}

void	set_width(char *str, int *x, t_utils *i)
{
	char *tmp;

	tmp = str;
	while (str[*x] && (ft_isdigit(str[*x])))
	{
		if (i->width == -1)
		{
			tmp += *x;
			i->width = ft_atoi(tmp);
		}
		*x += 1;
	}
}

void	set_prec(char *str, int *x, t_utils *i)
{
	char *tmp;

	if (str[*x] == '.')
		*x += 1;
	else
		return ;
	tmp = str;
	if (ft_isdigit(str[*x]) != 1 && (str[*x - 1] == '.'))
		i->precision = -69;
	while (str[*x] && (ft_isdigit(str[*x])) && (i->precision != -69))
	{
		if (i->precision == -1)
		{
			tmp += *x;
			i->precision = ft_atoi(tmp);
		}
		*x += 1;
	}
}

void	set_conv(char *str, int *x, va_list input, t_utils *i)
{
	if (str[*x] == 's' || str[*x] == 'S' || str[*x] == 'p' || str[*x] == 'd' ||
		str[*x] == 'D' || str[*x] == 'i' || str[*x] == 'o' || str[*x] == 'O' ||
		str[*x] == 'u' || str[*x] == 'U' || str[*x] == 'x' || str[*x] == 'X' ||
		str[*x] == 'c' || str[*x] == 'C' || str[*x] == '%')
	{
		i->cha_r = str[*x];
		if ((str[*x] == 's' || str[*x] == 'S') && (i->modifier != 6))
			convert_string(i, input);
		else if ((str[*x] == 'S' || str[*x] == 's') && (i->modifier == 6))
			convert_wchar(i, input);
		else if (str[*x] == 'p')
			convert_point(i, input);
		else if (str[*x] == 'c' || str[*x] == 'C')
			convert_char(i, input);
		else if (str[*x] == 'd' || str[*x] == 'D' || str[*x] == 'i')
			convert_int(i, input);
		else if (str[*x] == 'o' || str[*x] == 'O' || str[*x] == 'x' ||
			str[*x] == 'X' || str[*x] == 'u' || str[*x] == 'U')
			convert_unsigned_int(i, input);
		else if (str[*x] == '%')
			convert_percent(i);
		*x += 1;
	}
}

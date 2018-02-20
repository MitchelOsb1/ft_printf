/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/19 16:51:13 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(char *str, int *x, t_utils *i)
{
	if (str[*x] == '-')
		i->minus = true;
	else if (str[*x] == '+')
		i->plus = true;
	if (str[*x] == '0' && i->minus == false)
		i->zero = true;
	else if (str[*x] == ' ' && i->plus == false)
		i->space = true;
	else if (str[*x] == '#')
		i->hash = true;
	if (str[*x] == '-' || str[*x] == '0' || str[*x] == '+' || str[*x] == ' ' ||
	 str[*x] == '#')
		*x+=1;
}

void	set_mods(char *str, int *x, t_utils *i)
{
	if (str[*x] == 'h')
	{
		*x+= 1;
		i->modifier = str[*x] == 'h' ? 1 : 0;	
	}
	if (str[*x] == 'l')
	{
		*x+= 1;
		i->modifier = str[*x] == 'l' ? 3 : 2;
	}
	else if (str[*x] == 'j')
		i->modifier = 4;
	else if (str[*x] == 'z')
		i->modifier = 5;
	else if (str[*x] == 'q')
		i->modifier = 6;
}

void	set_width(char *str, int *x, t_utils *i)
{

	while (str[*x] && (ft_isdigit(str[*x]) != 0))
	{
		if (i->width == 0)
		{
			str += *x;
			i->width = ft_atoi(str);
		}
		*x += 1;
	}
}

void	set_prec(char *str, int *x, t_utils *i)
{

	if (str[*x] == '.')
		*x+= 1;
	if (ft_isdigit(str[*x]) != 1 && (str[*x - 1] == '.'))
		i->precision = -69;
	while (str[*x] && (ft_isdigit(str[*x])) && (i->precision != -69))
	{
		if (i->precision == 0)
		{
			str += *x;
			i->precision = ft_atoi(str);
		}
		*x+= 1;
	}
}


void	set_conv(char *str, int *x, va_list input, t_utils *i)
{
	if (str[*x] == 's' || str[*x] == 'S' || str[*x] == 'p' ||
		str[*x] == 'd' || str[*x] == 'D' || str[*x] == 'i' || str[*x] == 'o' ||
		str[*x] == 'O' || str[*x] == 'u' || str[*x] == 'U' || str[*x] == 'x' ||
		str[*x] == 'X' || str[*x] == 'c' || str[*x] == 'C')
	{
		if (str[*x] == 's')
			convert_string(i, input);
		// else if (str[*x] == 'S')
		// 	convert_wchar_s(i, input);
		// else if (str[*x] == 'p')
		// 	convert_point(i, input);
		// else if (str[*x] == 'c' || str[*x] == 'C')
		// 	convert_char(i, input);
		else if (str[*x] == 'd' || str[*x] == 'D' || str[*x] == 'i')
			convert_int(i, input);
		// else if (str[*x] == 'o' || str[*x] == 'O' || str[*x] == 'b')
		// 	convert_unsigned_int(i, input);
		// else if (str[*x] == 'x' || str[*x] == 'X' || str[*x] == 'u' ||
		// 		 str[*x] == 'U')
		// 	convert_unsigned_int(i, input);
		*x += 1;
	}
}

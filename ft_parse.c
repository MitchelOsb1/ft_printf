/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/19 14:26:47 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(char *str, int *x, t_tools i)
{
	if (OP(str[*x]))
	{
		if (str[*x] == '-')
			i.minus = true;
		else if (str[*x] == '0' && i.minus == false)
			i.zero = true;
		else if (str[*x] == '+')
			i.plus = true;
		else if (str[*x] == ' ' && i.plus == false)
			i.space = true;
		else if (str[*x] == '#')
			i.hash = true;
		x++;
	}
}

void	set_mods(char *str, int *x, t_tools i)
{
	if (MOD(str[*x]))
	{
		if (str[*x] == 'h')
		{
			x++;
			i.modifier = str[*x] == 'h' ? 1 : 0;
		}
		if (str[*x] == 'l')
		{
			x++;
			i.modifier = str[*x] == 'l' ? 3 : 2;
		}
		else if (str[*x] == 'j')
			i.modifier = 4;
		else if (str[*x] == 'z')
			i.modifier = 5;
		else if (str[*x] == 'q')
			i.modifier = 6;
	}
}

void	set_width(char *str, int *x, va_list input, t_tools i)
{

	if (ft_isdigit(str[*x]) != 0 | str[*x] == '*')
	{
		if (str[*x] == '*')
		{	
			i.star = true;
			i.width = va_arg(input, int);
		}
		else
			i.width = ft_atoi(str);
	}
}
	
void	set_prec(char *str, int *x, va_list input, t_tools i)
{

	if (str[*x] == '.')
	{
		i.dot = (va_arg(input, int));
		x++;
	}
	if (str[*x] == '*' || str[*x] == '-' ||
	 ft_isdigit(str[*x]) != 0)
	{
		if (str[*x] == '*')
		{
			i.star = true;
			i.precision = (va_arg(input, int));
			x++;
		}
		else
		{
			i.precision = va_arg(input, int);
			i.precision = ft_atoi(str);
		}
	}
}

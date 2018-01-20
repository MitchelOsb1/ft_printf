/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/20 15:26:31 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(char *str, int *x, t_utils *i)
{
	
	printf("\nset_flags%d", *x);
	while (OP(str[*x]) && str[*x] != '\0')
	{
		if (str[*x] == '-')
			i->minus = true;
		else if (str[*x] == '0' && i->minus == false)
			i->zero = true;
		else if (str[*x] == '+')
			i->plus = true;
		else if (str[*x] == ' ' && i->plus == false)
			i->space = true;
		else if (str[*x] == '#')
			i->hash = true;
		*x+= 1;
	}
}

void	set_conv(char *str, int *x, va_list input, t_utils *i)
{
	while (CONV(str[*x]))
	{
		if (str[*x] == 's')
			convert_string(i, input);
		// if (str[*x] == 'S')
		// 	convert_
	}
}

void	set_mods(char *str, int *x, t_utils *i)
{
	printf("\nset_mods:%d", *x);
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

void	set_width(char *str, int *x, va_list input, t_utils *i)
{

	printf("\nset_width:%d", *x);
	if (str[*x] == '*')
	{	
		i->star = true;
		i->width = va_arg(input, int);
	}
	else if (ft_isdigit(str[*x] != 0))
		i->width = ft_atoi(str);
}
	
void	set_prec(char *str, int *x, va_list input, t_utils *i)
{

	if (str[*x] == '.')
	{
		*x+= 1;
		if (ft_isdigit(str[*x]))
			i->dot = (str[*x] - 48);
	}
	while (str[*x] == '*' || str[*x] == '-' ||
	 ft_isdigit(str[*x]) != 0)
	{
		if (str[*x] == '*')
		{
			i->star = true;
			i->precision = (va_arg(input, int));
			*x+= 1;
		}
		else
		{
			i->precision = va_arg(input, int);
			i->precision = ft_atoi(str);
		}
		*x+= 1;
	}
	printf("\nset_prec:%d", *x);
}

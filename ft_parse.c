/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:53:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/21 00:01:28 by marvin           ###   ########.fr       */
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
		else if (str[*x] == 'S')
			convert_S;
		else if (str[*x] == 'p')
			convert_p;
		else if (str[*x] == 'c' || str[*x] == 'C')
			convert_char;
		else if (str[*x] == 'f' || str[*x] == 'F')
			convert_f;
		else if (str[*x] == 'd' || str[*x] == 'D' || str[*x] == 'i')
			convert_int;
		else if (str[*x] == 'o' || str[*x] == 'O' || str[*x] == 'b')
			convert_unsigned_int;
		else if (str[*x] == 'x' || str[*x] == 'X' || str[*x] == 'u' ||
				 str[*x] == 'U')
			convert_unsigned_int;
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

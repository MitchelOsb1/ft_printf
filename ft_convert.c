/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/13 14:55:52 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_string(t_utils *i, va_list input)
{
	int		x;
	int		a;
	char	cha_r;
	char	*va_string;

	x = -1;
	a = i->width;
	va_string = va_arg(input, char *);
	if (va_string == NULL)
		va_string = "(null)";
	i->len = ft_strlen(va_string);
	cha_r = i->zero == 1 ? cha_r = '0' : ' ';
	char_s(i, cha_r);
	while (++x < i->len && i->precision != -69)
		ft_putchar(va_string[x]);
	if (a > i->len && i->minus == true)
		while (i->width--)
			ft_putchar(cha_r);
}

// void	convert_wchar_s(t_utils *i, va_list input)
// {

// }

// void	convert_point(t_utils *i, va_list input)
// {
	
// }

// void	convert_int(t_utils *i, va_list input)
// {
	
// }

// void	convert_unsigned_int(t_utils *i, va_list input)
// {
	
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/12 18:53:24 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_string(t_utils *i, va_list input)
{
	int		x;
	char	*va_string;

	x = -1;
	va_string = va_arg(input, char *);
	i->len = ft_strlen(va_string);
	char_w(i, va_string);
	while (++x < i->len && i->minus == false)
		ft_putchar(va_string[x]);
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

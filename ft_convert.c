/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/26 13:05:13 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(t_utils *i, va_list input)
{
	char *str;
	char *va_string;
	static int x = 0;

	str = (char *)malloc(sizeof(i->width + 1));
	va_string = va_arg(input, char *);
	ft_strcpy
	ft_putstr("cmon");
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

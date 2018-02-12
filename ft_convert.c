/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/11 18:02:57 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(t_utils *i, va_list input)
{
	int x;
	char *str;
	char cha_r;
	char *va_string;

	x = ft_strlen(str);
	va_string = va_arg(input, char *);

	cha_r = i->zero == 1 ? cha_r = '0' : ' ';
	str = (char *)malloc(sizeof(x + 1));
	char_w(i, x);

	ft_strncpy(str, va_string, i->len);
	ft_putstr(str);
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

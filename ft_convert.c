/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/23 16:40:53 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_string(t_utils *i, va_list input)
{
	char *str;
	int x;
	static int z;

	printf("C_S:");
	x = i->width;
	str = va_arg(input, char *);
	if (i->width > 0)
		ft_putstr(ins_w(str, i->width, ' '));
	while (x--)
		ft_putchar(str[z++]);
	// printf("%s", str);
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

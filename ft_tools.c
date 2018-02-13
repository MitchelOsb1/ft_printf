 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:04:07 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/23 12:44:19 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
char t = 0, space, or another character
c = strlen
*/

void	char_w(t_utils *i, char *str)
{
	int			x;
	char		cha_r;
	static int	a = -1;

	x = i->width;
	cha_r = i->zero == 1 ? cha_r = '0' : ' ';
	if (i->precision < i->len && i->precision >= 0)
		i->len = i->precision;
	if (i->width > i->len)
		i->width -= i->len;
	while (++a < i->len && i->minus == true)
			ft_putchar(str[a]);
	if (x > i->len)
		while (i->width--)
			ft_putchar(cha_r);
}


/*

Handle: Minus, Zero

If precision is > lenth of string then find the difference 
Use the difference to putchar spacing
If minus
	Strcpy the putchar
else
	putchar strcpy

putstr

*/
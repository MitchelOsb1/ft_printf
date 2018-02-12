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

void	char_w(t_utils *i, int x)
{
	char cha_r;

	if (i->precision >= 0 || i->width >= 0)
		i->len = i->precision;
	if (i->width > x && i->minus == true)
	{
		
	}
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
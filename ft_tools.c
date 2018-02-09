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

void	ins_w(t_utils *i)
{
	char cha_r;

	cha_r = i->zero == 1 ? cha_r = '0' : ' ';
	if (i->width < i->precision || i->width > i->precision)
		i->len = i->precision;
	if (i->len == i->precision && i->width > i->len)
		i->width = i->width - i->len;
	while (i->width--)
		ft_putchar(cha_r);
}

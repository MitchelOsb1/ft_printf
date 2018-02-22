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

void	s_wpl(t_utils *i, char cha_r)
{
	int		x;

	x = i->width;
	if (i->precision < i->len && i->precision > 0)
		i->len = i->precision;
	if (i->width > i->len)
		i->width -= i->len;
	if ((x > i->len && i->minus == false) || (i->precision == -69))
		while (i->width--)
			ft_putchar(cha_r);
}

void	i_wpl(t_utils *i, char cha_r)
{
	int		x;
	char	sign;

	x = i->width;
	sign = i->plus == 1 || i->minus  == 1 ? sign = '-' : '+';
// -Set Len, Prec, Width --------------
	if (i->precision > i->len && i->len > 0)
		i->buf = i->precision - i->len;
	if (i->precision > i->width)
		i->width = i->precision - i->len;
	if (i->width > i->len + i->buf)
		i->width -= i->len + i->buf;
// -Handle Width Length-----------------
	if ((x > i->len && i->minus == false && i->zero == false) || (i->precision == -69))
		while (i->width--)
			ft_putchar(cha_r);
	if (x > i->len && i->minus == false && i->zero == true)
		while (i->width--)
			ft_putchar(' ');
// -Handle Sign--------------------------
	if (i->minus == true || i->plus == true)
		ft_putchar(sign);
// -Handle Buffer------------------------
	if (i->buf >= 0)
		while (i->buf--)
			ft_putchar('0');
}

/*

	if (i->precision > i->len && i->len >= 0)
		i->buf = i->precision - i->len;
	if (i->width > i->len)
			i->width -= i->buf + i->len;
	if (x > i->len && i->minus == false && i->zero == true)
		while (i->width--)
			ft_putchar(' ');
	if (x > i->len && i->minus == false && i->zero == false)
		while (i->width--)
			ft_putchar(cha_r);
	if (x > i->len && i->minus == false && i->precision > i->len)
		while (i->buf--)
			ft_putchar('0');

*/
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

	x = i->width;
	if (i->precision > i->len && i->len > 0)
		i->buf = i->precision - i->len;
	if (i->precision > i->width)
		i->width = i->precision - i->len;
	if (i->width > i->len)
		i->width -= i->len + i->buf;
	if ((x > i->len && i->minus == false && i->zero == false) || (i->precision == -69))
		while (i->width--)
			ft_putchar(cha_r);
	if (x > i->len && i->minus == false && i->zero == true)
		while (i->width--)
			ft_putchar(' ');
}

void	i2_wpl(t_utils *i, char *str, char cha_r, char sign, int w)
{
	int		count;
	char	buf;

	count = -1;
	buf = i->precision < i->len ? buf = ' ' : '0';
	if ((i->minus == true && x < 0) || (i->plus == true && x > 0) || (x < 0))
		ft_putchar(sign);
	if (i->buf > 0)
		while (i->buf--)
			ft_putchar(buf);
	while (++count < i->len && i->precision != -69)
	{
		if (str[count] == '+' || str[count] == '-')
			count++;
		ft_putchar(str[count]);
	}
	if ((w > i->len && i->minus == true))
		while (i->width--)
			ft_putchar(cha_r);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:20:49 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/07 09:17:17 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	c_wpl(t_utils *i, unsigned char cha_r)
{
	if (i->precision < i->len && i->precision >= 0)
		i->len = i->precision;
	if (i->precision >= 0)
		i->width -= i->len;
	else if (i->width >= 0 && i->precision != -69)
		i->width -= i->len;
	if (i->minus == 0 && i->width > 0)
		while (i->width-- && i->zero == 1)
			ft_putchar('0');
	else if (i->minus == 0 && i->width > 0)
		while (i->width--)
			ft_putchar(' ');
	ft_putchar(cha_r);
	if (i->width > 0)
		while (i->width--)
			ft_putchar(' ');
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:20:49 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/04 13:04:04 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
			ft_putc_c(cha_r, &(i->count));
}

void	c_wpl(t_utils *i, unsigned char cha_r)
{
	char buf;

	buf = ' ';
	if (i->zero == 1)
		buf = '0';
	if (i->precision < i->len && i->precision >= 0)
		i->len = i->precision;
	if (i->precision >= 0)
		i->width -= i->len;
	else if (i->width >= 0 && i->precision != -69)
		i->width -= i->len;
	if (i->minus == 0 && i->width > 0)
		while (i->width-- && i->width > 0)
			ft_putc_c(buf, &(i->count));
	ft_putc_c(cha_r, &(i->count));
	if (i->width > 0)
		while (i->width-- && i->width > 0)
			ft_putc_c(' ', &(i->count));
}

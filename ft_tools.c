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
	int	x;
	int	len;

	x = i->width;
	len = i->len;
	if (i->precision < i->len && i->precision >= 0)
		i->len = i->precision;
	if (i->width > i->len)
		i->width -= i->len;
	if ((x > i->len && i->minus == false) || (i->precision == 69))
		while (i->width--)
			ft_putchar(cha_r);
}

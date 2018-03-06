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

void	i_wpl(t_utils *i, char cha_r, int w)
{
	if (cha_r == '0' && i->i_nt == 0)
		cha_r = ' ';
	if (i->precision > i->len && i->i_nt >= 0)
		i->buf = i->precision - i->len;
	if (i->precision > i->len && i->i_nt < 0)
		i->buf = i->precision - i->len + 1;
	if (i->precision > i->width && i->width > 0)
		i->width = i->precision - i->len - i->buf;
	if (i->width > i->len && i->len > 0 && i->precision != -69)
		i->width -= i->len + i->buf;
	if ((i->plus == 1 || i->space == 1) && i->i_nt > 0)
		i->width -= 1;
	if (w > i->len && i->minus == false && i->zero == false)
		while (i->width--)
			ft_putchar(cha_r); //cha_r
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt > 0 && i->space == 0)
		while (i->width--)
			ft_putchar('0');
}

void	i2_wpl(t_utils *i, char *str, char cha_r, char sign, int w)
{
	int			count;
	char		buf;
	char		z_ero;
	long int	x;

	x = i->i_nt;
	count = -1;
	buf = '0';
	z_ero = '0';
	if (i->zero == 1 && i->i_nt == 0 && i->precision > 0)
		z_ero = ' ';
	if (i->precision < i->len)
		buf = ' ';
	if (i->space == 1 && i->i_nt >= 0)
		sign = ' ';
	if ((i->minus == true && x < 0) || (i->plus == true && x > 0) || (x < 0) || (i->space == 1))
		ft_putchar(sign);
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt > 0 && i->space == 1)
		while (i->width--)
			ft_putchar('0');
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt < 0)
		while (i->width--)
			ft_putchar('0');
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt == 0)
		while (i->width--)
			ft_putchar(z_ero);
	if (i->buf)
		while (i->buf--)
			ft_putchar('0');
	while (++count < i->len && i->precision != -69)
	{
		if (str[count] == '+' || str[count] == '-')
			count++;
		ft_putchar(str[count]);
	}
	if (w > i->len && i->minus == true && i->zero == false)
		while (i->width--)
			ft_putchar(cha_r);
	if (w > i->len && i->minus == true && i->zero == true)
		while (i->width--)
			ft_putchar(' ');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:20:03 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/28 15:55:47 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	h_mps(t_utils *i, char sign, long long int x)
{
	if (i->plus == 1 && i->minus == 0)
	{
		i->plus = 1;
		sign = '+';
	}
	if (i->minus == 1 && i->plus == 1 && i->i_nt > 0)
	{
		sign = '+';
		return (sign);
	}
	if ((i->minus == 1 && i->plus == 1) || i->minus == 1)
	{
		i->minus = 1;
		i->plus = 0;
		sign = '-';
	}
	if ((i->minus == 0 && i->plus == 0) || (x < 0))
		sign = '-';
	if (i->space == 1 && x > 0 && i->plus == 0)
		sign = ' ';
	return (sign);
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
	if ((i->width > i->len && i->len > 0) && i->precision != -69 && i->precision != 0)
		i->width -= i->len + i->buf;
	if ((i->plus == 1 || i->space == 1) && i->i_nt > 0)
		i->width -= 1;
	if (w > i->len && i->minus == false && i->zero == false)
		while (i->width--)
			ft_putc_c(cha_r, &(i->count));
}

void	i2_wpl(t_utils *i, char sign, int w)
{
	char buff;

	buff = '0';
	if (i->precision > i->len)
		buff = ' ';
	if (i->space == 1 && i->i_nt >= 0 && i->plus == 0)
		sign = ' ';
	if ((i->minus == true && i->i_nt < 0) || (i->plus == true && i->i_nt > 0)
		|| (i->i_nt < 0) || (i->space == 1) || (i->plus == 1 && i->i_nt == 0))
		ft_putc_c(sign, &(i->count));
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt > 0 && i->space == 0)
		while (i->width--)
			ft_putc_c(buff, &(i->count));
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt > 0 && i->space == 1)
		while (i->width--)
			ft_putc_c(buff, &(i->count));
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt < 0)
		while (i->width--)
			ft_putc_c('0', &(i->count));
}

void	i3_wpl(t_utils *i, int w, long long int x)
{
	char		z_ero;
	int			count;
	char		buf;

	count = -1;
	z_ero = '0';
	buf = '0';
	if (i->zero == 1 && i->i_nt == 0 && i->precision > 0)
		z_ero = ' ';
	if (i->precision < i->len)
		buf = ' ';
	if (w > i->len && i->minus == false && i->zero == true && i->i_nt == 0)
		while (i->width--)
			ft_putc_c(z_ero, &(i->count));
	if (i->buf)
		while (i->buf--)
			ft_putc_c(buf, &(i->count));
	if (i->i_nt == 0 && (i->precision == -69 || i->precision == 0))
		return ;
	ft_putc_nbr(x, &(i->count));
}

void	i4_wpl(t_utils *i, char cha_r, int w)
{
	if (w > i->len && i->minus == true && i->zero == false)
		while (i->width--)
			ft_putc_c(cha_r, &(i->count));
	if (w > i->len && i->minus == true && i->zero == true)
		while (i->width--)
            ft_putc_c(' ', &(i->count));
}

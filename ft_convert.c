/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/14 08:58:55 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_string(t_utils *i, va_list input)
{
	int		x;
	int		a;
	char	cha_r;
	char	*va_string;

	x = -1;
	a = i->width;
	va_string = va_arg(input, char *);
	if (va_string == NULL)
		va_string = "(null)";
	i->len = ft_strlen(va_string);
	cha_r = i->zero == 1 ? cha_r = '0' : ' ';
	s_wpl(i, cha_r);
	while (++x < i->len && i->precision != -69)
		ft_putc_c(va_string[x], &(i->count));
	if (a > i->len && i->minus == true)
		while (i->width--)
			ft_putc_c(cha_r, &(i->count));
}

void	convert_char(t_utils *i, va_list input)
{
	unsigned char cha_r;

	cha_r = va_arg(input, int);
	if (i->cha_r == 'C')
		i->width = -2; // Fix to account for uppercase C
	c_wpl(i, cha_r);
}

void	convert_int(t_utils *i, va_list input)
{
	int			w;
	char		cha_r;
	char		*str;
	char		sign;
	long int	x;

	w = i->width;
	if (i->modifier > -1)
		i->i_nt = i_mod(i, input);
	else
		i->i_nt = va_arg(input, int);
	x = i->i_nt;
	str = ft_itoa(x);
	i->len = ft_strlen(str);
	cha_r = i->zero == 1 ? cha_r = '0' : ' ';
	sign = '0';
	sign = h_mps(i, sign, x);
	i_wpl(i, cha_r, w);
	i2_wpl(i, sign, w);
	i3_wpl(i, str, w);
	i4_wpl(i, cha_r, w);
	ft_strdel(&str);
}

void	convert_unsigned_int(t_utils *i, va_list input)
{
	unsigned long long int num;

	if (i->modifier > -1)
		num = ui_mod(i, input);
	else
		num = va_arg(input, unsigned int);
	if (i->cha_r == 'o' || i->cha_r == 'O')
		o_wpl(i, num);
	else if (i->cha_r == 'u' || i->cha_r == 'U')
		u_wpl(i, num);
	else if (i->cha_r == 'x' || i->cha_r == 'X')
		x_wpl(i, num);
}

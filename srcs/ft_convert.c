/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:19 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/09 20:10:50 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	cha_r = i->zero == 1 ?
		cha_r = '0' : ' ';
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

	cha_r = (unsigned char)va_arg(input, int);
	c_wpl(i, cha_r);
}

void	convert_int(t_utils *i, va_list input)
{
	int				w;
	char			cha_r;
	char			*str;
	char			sign;
	long long int	x;

	w = i->width;
	x = i_mod(i, input);
	str = ft_itoa(x);
	i->i_nt = x;
	i->len = ft_strlen(str);
	free(str);
	cha_r = i->zero == 1 ?
		cha_r = '0' : ' ';
	sign = '0';
	sign = h_mps(i, sign, x);
	i_wpl(i, cha_r, w);
	i2_wpl(i, sign, w);
	i3_wpl(i, w, x);
	i4_wpl(i, cha_r, w);
}

void	convert_unsigned_int(t_utils *i, va_list input)
{
	unsigned long long int num;

	num = ui_mod(i, input);
	if (i->cha_r == 'o' || i->cha_r == 'O')
		o_wpl(i, num);
	else if (i->cha_r == 'u' || i->cha_r == 'U')
		u_wpl(i, num);
	else if (i->cha_r == 'x' || i->cha_r == 'X')
		x_wpl(i, num);
}

void	convert_point(t_utils *i, va_list input)
{
	char					*str;
	unsigned long long int	num;

	num = va_arg(input, unsigned long long int);
	str = c_hexoa(num, i);
	handl_p(i, str);
	free(str);
}

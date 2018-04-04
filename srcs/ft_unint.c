/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:24:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/04 15:40:07 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	o_wpl(t_utils *i, unsigned long int num)
{
	char	*str;

	if (num <= 9223372036854775807)
		str = c_octoa(num);
	else
		str = (NULL);
	if (str == NULL)
		return ;
	i->len = ft_strlen(str);
	p_num(i, num);
	handl_ui(i, num);
	print_ui(i, num, str);
	ft_strdel(&str);
}

void	u_wpl(t_utils *i, unsigned long int num)
{
	char	*str;

	if (num >= (2 ^ 32))
		str = ft_ui_ll_toa(num);
	else if (num <= ((2 ^ 32) - 1))
		str = ft_ui_toa(num);
	else
		str = (NULL);
	i->len = ft_strlen(str);
	p_num(i, num);
	handl_ui(i, num);
	print_ui(i, num, str);
	ft_strdel(&str);
}

void	x_wpl(t_utils *i, unsigned long int num)
{
	char	*str;

	str = c_hexoa(num, i);
	i->len = ft_strlen(str);
	p_num(i, num);
	handl_ui(i, num);
	print_ui(i, num, str);
	ft_strdel(&str);
}

void	convert_percent(t_utils *i)
{
	if (i->zero == 1)
		while (i->width-- && i->width > 0)
			ft_putc_c('0', &(i->count));
	if (i->minus == 0)
		while (i->width-- && i->width > 0)
			ft_putc_c(' ', &(i->count));
	ft_putc_c('%', &(i->count));
	if (i->minus == 1)
		while (i->width-- && i->width > 0)
			ft_putc_c(' ', &(i->count));
}

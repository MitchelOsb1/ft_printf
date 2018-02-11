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

void	ins_w(t_utils *i, int x)
{
	char cha_r;

	cha_r = (i->zero == 1 ? cha_r = '0' : ' ');
	if (i->precision > x)
		i->len = i->precision;
	if (i->width >= 0)
		i->len = i->width - x;
	while (i->len > 0)
	{
		ft_putchar(cha_r);
		i->len = i->len - 1;
	}
}

/*
	Set len to the amount of characters its going to be pushed over
	Width and Predision will decide the amount of characters from the string
*/


	// if (i->width == x || i->precision == x)
	// 	i->len = x;
	// if (i->width >= 0 && i->precision >= 0)
	// {
    // 	if (i->width > i->precision)
    // 	{
	// 		i->len = i->width;
	// 		while (i->len)
	// 		{
	// 			ft_putchar(cha_r);
	// 			i->len = i->len - 1;
	// 		}
	// 	}
	// 	else if (i->width < i->precision)
    //     {
	// 		i->len = i->precision;
	// 	}
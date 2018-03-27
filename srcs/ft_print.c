/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:24:38 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/27 14:59:00 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_prefix(char *str, int begin, int end, t_utils *i)
{
	int z;

	z = 0;
	while (z < begin && str[z])
		z++;
	while (z < end && str[z])
	{
		ft_putc_c(str[z], &(i->count));
		z++;
	}
}

void	print_postfix(char *str, int x, t_utils *i)
{
	while (str[x])
	{
		ft_putc_c(str[x], &(i->count));
		x++;
	}
}

void	print_hex_addr(unsigned long long int num, t_utils *i)
{
	if (i->cha_r == 'x' && num)
		ft_putc_s("0x", &(i->count));
	if (i->cha_r == 'X' && num)
		ft_putc_s("0X", &(i->count));
	if (i->cha_r == 'o' || i->cha_r == 'O')
		if (i->precision - i->len < 0 && num == 0)
			ft_putc_c('0', &(i->count));
	i->hash = 0;
}

void	print_ptr_addr(t_utils *i)
{
	ft_putc_s("0x", &(i->count));
}

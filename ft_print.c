/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:24:38 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/12 19:16:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(char *str, int x, t_utils *i)
{
	int i;

	i = 0;
	while (str[i] && i < x)
	{
		ft_putc_c(str[i], &(i->count));
		i++;
	}
}

void	print_postfix(char *str, int x, t_utils *i)
{
	while (str[x])
	{
		ft_putc_c(str[i], &(i->count));
		x++;
	}
}

void	print_hex_addr(t_utils *i, unsigned long long int num)
{
	if (i->cha_r == 'x' && num)
		ft_putc_s("0x", i);
	if (i->cha_r == 'X' && num)
		ft_putc_s("0X", i);
	if (i->cha_r == 'o' || i->cha_r == 'O')
		if (i->precision - i->len < 0 && num)
			ft_putc_c('0', i);
	i->hash = 0;
}
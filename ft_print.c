/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:24:38 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/11 14:30:20 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(char *str, int x)
{
	int i;

	i = 0;
	while (str[i] && i < x)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_postfix(char *str, int x)
{
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

void	print_hex_addr(t_utils *i, unsigned long long int num)
{
	if (i->cha_r == 'x' && num)
		ft_putstr("0x");
	if (i->cha_r == 'X' && num)
		ft_putstr("0X");
	if (i->cha_r == 'o' || i->cha_r == 'O')
		if (i->precision - i->len < 0 && num)
			ft_putchar('0');
	i->hash = 0;
}
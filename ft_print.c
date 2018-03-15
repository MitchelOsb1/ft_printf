/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:24:38 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/15 10:52:35 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(char *str, int x, t_utils *i)
{
	int z;

	z = 0;
	while (str[z] && z < x)
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


	// if ((tools->prec == -100 || tools->prec == -1) && num == 0 &&
	// 	tools->hashtag == 1 && (tools->brand == 'o' || tools->brand == 'O'))
	// 	ft_print_putchar('0', &(tools->retrn));
		
	// if (tools->hashtag == 1 && tools->width <= 0)
	// 	ft_print_address(tools, num);

	// else if (tools->hashtag == 1 && tools->zeros == 1)
	// 	ft_print_address(tools, num);

	// if (tools->zeros == 1)
	// 	while (tools->width-- > 0)
	// 		ft_print_putchar('0', &(tools->retrn));

	// else if (tools->negative == 0)
	// 	while (tools->width-- > 0)
	// 		ft_print_putchar(' ', &(tools->retrn));

	// if (tools->hashtag == 1)
	// 	ft_print_address(tools, num);

	// while (tools->prec-- > 0 && dis != 0)
	// 	ft_print_putchar('0', &(tools->retrn));

	// if (!(dis == 1 && num == 0))
	// 	ft_print_putstr(dt, &(tools->retrn));

	// while (tools->width-- > 0)
	// 	ft_print_putchar(' ', &(tools->retrn));
		

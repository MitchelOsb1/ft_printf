/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handl_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 10:25:05 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/14 11:34:24 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    handl_ui(t_utils *i, unsigned long long int x)
{
    i->zero = (i->precision == -69 || i->space == 0 || i->precision >= 0) ?
        i->zero = 0 : i->zero;
    i->width = ((i->precision == -69 || i->precision == 0) && x == 0) ?
        i->width = i->width + 1 : i->width;
    i->width = ((i->cha_r == 'x' || i->cha_r == 'X') && (i->hash == 1)) ?
        i->width = i->width - 2 : i->width;
    i->width = ((i->cha_r == 'o' || i->cha_r == 'O') && (i->hash == 1)) ?
        i->width = i->width - 1 : i->width;
    if (i->precision > 0 && (i->precision > i->len))
        i->width -= i->precision;
    else if (i->precision == -69 || i->precision == 0)
        i->width -= 1;
    else
        i->width -= i->len;
    i->precision = (i->precision != 69 || i->precision >= 0) ?
        i->precision = i->precision - i->len : i->precision;
    i->width = (i->plus == 1) ? i->width = i->width - 1 : i->width;
}

// void    handl_ui(t_utils *i, unsigned long long int x)
// {
// 	if (i->precision == -100 || i->space == 1 || i->precision >= 0)
// 		i->zero = 0;
// 	if ((i->precision == -100 || i->precision == 0) && x == 0)
// 		i->width += 1;
// 	if ((i->cha_r == 'x' || i->cha_r == 'X') && (i->hash == 1))
// 		i->width -= 2;
// 	if ((i->cha_r == 'o' || i->cha_r == 'O') && i->hash == 1)
// 		i->width -= 1;
// 	if (i->precision > 0 && (i->len < i->precision))
// 		i->width -= i->precision;
// 	else if (i->precision == -100 || i->precision == 0)
// 		i->width -= 1;
// 	else
// 		i->width -= i->len;
// 	if (i->precision != -100 && i->precision >= 0)
// 		i->precision -= i->len;
// 	if (i->plus == 1)
// 		i->width -= 1;
// }

void    print_ui(t_utils *i, unsigned long long int x, char *str)
{
    if (i->cha_r == 'o' || i->cha_r == 'O')
        if (x == 0 && i->hash == 1 && (i->precision == -69 ||
            i->precision == -1))
            ft_putc_c('0', &(i->count));
    if ((i->hash == 1 && i->width <= 0) || (i->hash == 1 && i->zero == 1))
        print_hex_addr(x, i);
    while (i->width-- > 0 && i->zero == 1)
        ft_putc_c('0', &(i->count));
    while (i->width-- > 0 && i->minus == 0)
        ft_putc_c(' ', &(i->count));
    if (i->hash == 1)
        print_hex_addr(x, i);
    while ((i->precision-- > 0 && ((i->precision > -1 || i->precision == -69)
        || (x == 0 && i->hash == 1)) && (i->cha_r == 'o' || i->cha_r == 'O')))
        ft_putc_c('0', &(i->count));
    if (!(((i->precision > 0 || i->precision == -69) || (i->hash == 1 && x == 0))
        && (i->cha_r == 'o' || i->cha_r == 'O')))
        ft_putc_s(str, &(i->count));
    while (i->width-- > 0)
        ft_putc_c(' ', &(i->count));
}

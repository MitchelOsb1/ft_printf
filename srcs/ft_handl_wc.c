/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handl_wc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:48:18 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/21 18:03:33 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    handl_wp_c(t_utils *i, wchar_t wide)
{
    if (i->minus == 0)
        while (i->width-- > 0)
            ft_putc_c(' ', &(i->count));
    ft_putc_s(c_unitoa(wide), &(i->count));
    if (i->minus == 1)
        while (i->width-- > 0)
            ft_putc_c(' ', &(i->count));
}

void    handl_wp_s(t_utils *i, char *str)
{
    if (i->minus == 0)
        while (i->width-- > 0)
            ft_putc_c(' ', &(i->count));
    if (i->precision != -69)
        ft_putc_s(str, &(i->count));
    if (i->minus == 1)
        while (i->width-- > 0)
            ft_putc_c(' ', &(i->count));
}

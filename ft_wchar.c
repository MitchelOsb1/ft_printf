/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 08:58:43 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/21 17:13:01 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_wchar(t_utils *i, va_list input)
{
    char *ret;

    ret = NULL;
    if (i->cha_r == 'C')
        ret = handl_w_c(i, input);
    if (i->cha_r == 'S')
        ret = handl_w_s(i, input);
    if (!(ret))
        return ;
    if (i->minus == 0)
        while (i->width-- && i->width > 0)
            ft_putc_c(' ', &(i->count));
    if (i->precision != -69 || i->cha_r == 'C')
        ft_putc_s(ret, &(i->count));
    if (i->minus == 1)
        while (i->width-- && i->width > 0)
            ft_putc_c(' ', &(i->count));
}

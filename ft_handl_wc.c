/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handl_wc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:48:18 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/21 17:20:06 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *handl_w_c(t_utils *i, va_list input)
{
    char    *str;
    wchar_t wide;

    wide = va_arg(input, wint_t);
    str = c_unitoa(wide);
    i->len = ft_strlen(str);
    i->width -= i->len;
    return (c_unitoa(wide));
}

char    *handl_w_s(t_utils *i, va_list input)
{
    char    *str;
    wchar_t *wide;

    wide = (wchar_t *)va_arg(input, wchar_t *);
    str = c_unitoa(*wide++);
    if ((i->modifier != 6) && (ft_strlen(str) > 1))
        return (0);
    while (*wide)
        str = ft_strjoin(str, c_unitoa(*wide++));
    i->len = ft_strlen(str);
    if (i->precision == -69)
        i->len = 0;
    i->width -= i->len;
    return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 08:58:43 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/21 18:31:29 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_wchar(t_utils *i, va_list input)
{
    if (i->cha_r == 'C')
        handl_w_c(i, input);
    if (i->cha_r == 'S')
        handl_w_s(i, input);
}

void    handl_w_c(t_utils *i, va_list input)
{
    char    *str;
    wchar_t wide;

    wide = va_arg(input, wint_t);
    str = c_unitoa(wide);
    i->len = ft_strlen(str);
    i->width -= i->len;
    handl_wp_c(i, wide);
    free(str);
}

void    handl_w_s(t_utils *i, va_list input)
{
    char    *str;
    wchar_t *wide;

    wide = (wchar_t *)va_arg(input, wchar_t *);
    str = c_unitoa(*wide++);
    if ((i->modifier != 6) && (ft_strlen(str) > 1))
        return ;
    while (*wide)
        str = ft_strjoin(str, c_unitoa(*wide++));
    i->len = ft_strlen(str);
    if (i->precision == -69)
        i->len = 0;
    i->width -= i->len;
    handl_wp_s(i, str);
    free(str);
}

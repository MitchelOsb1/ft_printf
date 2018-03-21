/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:24:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/20 11:06:18 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    o_wpl(t_utils *i, unsigned long int num)
{
    char    *str;

    if (num <= 9223372036854775807)
        str = c_octoa(num);
    else
        str = (NULL);
    i->len = ft_strlen(str);
    p_num(i, num);
    handl_ui(i, num);
    print_ui(i, num, str);
    free(str);
}

void    u_wpl(t_utils *i, unsigned long int num)
{
    char    *str;

    if (num > ((2^32)-1))
        str = ft_ui_ll_toa(num);
    else if (num <= ((2^32)-1))
        str = ft_ui_toa(num);
    else
        str = (NULL);
    i->len = ft_strlen(str);
    p_num(i, num);
    handl_ui(i, num);
    print_ui(i, num, str);
    free(str);
}

void    x_wpl(t_utils *i, unsigned long int num)
{
    char    *str;

    str = c_hexoa(num, i);
    i->len = ft_strlen(str);
    p_num(i, num);
    handl_ui(i, num);
    print_ui(i, num, str);
    free(str);
}

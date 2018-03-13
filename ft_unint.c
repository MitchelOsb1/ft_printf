/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:24:51 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/12 11:00:36 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    o_wpl(t_utils *i, unsigned long int num)
{
    char    *str;
    int     x;

    str = c_otoa(num);
    x = ft_strlen(str);
    i->len = x;
    handl_ui(i, num);
    print_ui(i, num);
}

// void    u_wpl(t_utils *i, unsigned long int num)
// {
//
// }
//
// void    x_wpl(t_utils *i, unsigned long int num)
// {
//
// }

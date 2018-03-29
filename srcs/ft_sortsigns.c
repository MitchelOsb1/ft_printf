/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortsigns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 08:49:55 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/28 16:36:49 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long int  i_mod(t_utils *i, va_list input)
{
    if (i->modifier == 0)
        return ((short int)va_arg(input, void*));
    else if (i->modifier == 1)
        return ((char)va_arg(input, void*));
    else if (i->modifier == 2)
        return ((long int)va_arg(input, void*));
    else if (i->modifier == 3)
        return ((long long int)va_arg(input, void*));
    else if (i->modifier == 4)
        return ((intmax_t)va_arg(input, void*));
    else if (i->modifier == 5)
        return ((size_t)va_arg(input, void*));
    else if (i->modifier == 6)
        return ((int)va_arg(input, void*));
    if (i->cha_r == 'd' || i->cha_r == 'i')
        return ((int)va_arg(input, void*));
    else
        return (0);
}

unsigned long long int  ui_mod(t_utils *i, va_list input)
{
    if (i->modifier == 0)
        return ((unsigned short int)va_arg(input, void *));
    else if (i->modifier == 1)
        return ((unsigned char)va_arg(input, void *));
    else if (i->modifier == 2)
        return ((unsigned long int)va_arg(input, void *));
    else if (i->modifier == 3)
        return ((unsigned long long int)va_arg(input, void *));
    else if (i->modifier == 4)
        return ((intmax_t)va_arg(input, void *));
    else if (i->modifier == 5)
        return ((size_t)va_arg(input, void *));
    else if (i->modifier == 6)
        return ((unsigned int)va_arg(input, void *));
    if (i->cha_r == 'U' || i->cha_r == 'O')
        return ((unsigned long long int)va_arg(input, void *));
    else if (i->cha_r == 'o' || i->cha_r == 'u' || i->cha_r == 'x' ||
        i->cha_r == 'X')
        return ((unsigned int)va_arg(input, void *));
    return ((unsigned long long int)NULL);
}

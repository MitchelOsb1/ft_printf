/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortsigns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 08:49:55 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/12 10:19:48 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long   i_mod(t_utils *i, va_list input)
{
    if (i->modifier == 0)
        return ((short int)va_arg(input, int));
    else if (i->modifier == 1)
        return ((char)va_arg(input, int));
    else if (i->modifier == 2)
        return (va_arg(input, long int));
    else if (i->modifier == 3)
        return (va_arg(input, long long int));
    else if (i->modifier == 4)
        return (va_arg(input, intmax_t));
    else if (i->modifier == 5)
        return (va_arg(input, size_t));
    else if (i->modifier == 6)
        return (va_arg(input, int));
    else
        return (0);
}

long long   ui_mod(t_utils *i, va_list input)
{
    if (i->modifier == 0)
        return ((unsigned short int)va_arg(input, unsigned int));
    else if (i->modifier == 1)
        return ((unsigned char)va_arg(input, unsigned int));
    else if (i->modifier == 2)
        return (va_arg(input, unsigned long int));
    else if (i->modifier == 3)
        return (va_arg(input, unsigned long long int));
    else if (i->modifier == 4)
        return (va_arg(input, intmax_t));
    else if (i->modifier == 5)
        return (va_arg(input, size_t));
    else if (i->modifier == 6)
        return (va_arg(input, unsigned int));
    return (0);
}

char    *c_otoa(unsigned long int num)
{
    char            *str;
    unsigned int    x;

    x = 0;
    if (num)
    {
        str = ft_strnew(24);
        if (num < x)
            return ("Unsigned Only");
        if (num == 0)
        {
            str[x] = '0';
            x++;
        }
        while (num)
        {
            str[x] = (num % 8) + 48;
            num = num / 8;
            x++;
        }
        str[x] = '\0';
        return (ft_strrev(str));
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 09:54:46 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/14 09:01:44 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strrev(char *str)
{
    int x;
    int i;
    char *tmp;

    i = 0;
    x = ft_strlen(str);
    tmp = ft_strnew(x);
    x--;
    bzero(tmp, x);
    while (str[x])
    {
        tmp[i] = str[x];
        x--;
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char    *ft_uitoa(unsigned int n)
{
        unsigned int    sign;
        unsigned int    count;
        char    *str;

        count = 1;
        sign = n;
        while (sign /= 10)
                count++;
        sign = n < 0 ? 1 : 0;
        count = n < 0 ? count += 1 : count;
        if (n == -2147483648)
                return (str = ft_strdup("-2147483648"));
        str = ft_strnew(count);
        if (!str)
                return (NULL);
        if (sign == 1)
                str[0] = '-';
        n = n < 0 ? n *= -1 : n;
        while (--count >= sign)
        {
                str[count] = n >= 10 ? (n % 10) + 48 : n + 48;
                n /= 10;
        }
        str[ft_strlen(str)] = '\0';
        return (str);
}

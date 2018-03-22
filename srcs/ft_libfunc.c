/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 09:54:46 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/21 18:31:54 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void    ft_putc_nbr(long long int num, int *int_cnt)
{
        if (num == (2^63))
        {
                ft_putc_s("-9223372036854775808", int_cnt);
                return ;
        }
        if (num < 0)
        {
                ft_putc_nbr(-num, int_cnt);
        }
        else if (num >= 10)
        {
                ft_putc_nbr((num / 10), int_cnt);
                ft_putc_nbr((num % 10), int_cnt);
        }
        else
                ft_putc_c((num + 48), int_cnt);
}

char    *ft_ui_toa(unsigned int n)
{
        unsigned int    sign;
        unsigned int    count;
        char            *str;

        count = 1;
        sign = n;
        while (sign /= 10)
                count++;
        str = ft_strnew(count);
        if (!(str))
                return (NULL);
        while (count--)
        {
                str[count] = n >= 10 ? (n % 10) + 48 : n + 48;
                n /= 10;
        }
        str[ft_strlen(str)] = '\0';
        return (str);
}

char    *ft_ui_ll_toa(unsigned long long int n)
{
        unsigned long long int  sign;
        unsigned int            count;
        char                    *str;

        count = 1;
        sign = n;
        while (sign /= 10)
                count++;
        str = ft_strnew(count);
        if (!str)
                return (NULL);
        while (count--)
        {
                str[count] = n >= 10 ? (n % 10) + 48 : n + 48;
                n /= 10;
        }
        str[ft_strlen(str)] = '\0';
        return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 09:54:46 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/11 10:06:17 by mosborne         ###   ########.fr       */
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

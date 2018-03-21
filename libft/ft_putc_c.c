/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:04:46 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/21 10:39:54 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putc_c(char c, int *cnt_ret)
{
    *cnt_ret += 1;
    write(1, &c, 1);
}

void    ft_putc_s(char *str, int *cnt_ret)
{
	while (*str)
		ft_putc_c(*str++, cnt_ret);
}

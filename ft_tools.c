/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:04:07 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/22 15:25:14 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
char t = 0, space, or another character
c = count
*/

char	*ins_w(char *str, int c, char t)
{
	char *tmp;
	static int x = 0;
	static int i = 0;
	
	if (c > ft_strlen(str))
		x = c - ft_strlen(str);
	tmp = ft_strnew(x);
	if (c > 0)
	{
		while (x)
		{
			tmp[i] = t;
			x--;
			i++;
		}
	}
	while (tmp[x] && str[i] && x < c)
	{
		tmp[x] = str[i];
		x++;
		i++;
	}
	return (tmp);
}

// char	*handle_w(t_utils *i, char *str, va_list input)
// {
// 	static int x = 0;
// 	static int c = 0;

// 	if (i->width > ft_strlen(str))
// 		x = (i->width - ft_strlen(str));
// 	if (i->width < ft_strlen(str))
// 		ft_putstr(str);
// }

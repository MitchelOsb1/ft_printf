 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:04:07 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/23 12:44:19 by mosborne         ###   ########.fr       */
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
	
	tmp = ft_strnew(c);
	while (tmp[x])
	{
		tmp[x] = t;
		x++;
	}
	str = ft_strjoin(tmp, str);
	free(tmp);
	return (str);
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

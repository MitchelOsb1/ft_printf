/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:04:07 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/21 18:46:33 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_w(t_utils *i, char *str, va_list input)
{
	static int x = 0;
	static int c = 0;

	if (i->width > ft_strlen(str))
		x = (i->width - ft_strlen(str));
	if (i->width < ft_strlen(str))
		ft_putstr(str);
}
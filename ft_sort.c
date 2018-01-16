/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:57:47 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/15 18:35:54 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_width(char *str, int i)
{

	while (str[i]) // "%1" "%-"
	{
		if (isdigit(str[i])) // "%12" "%-1"
		{
			i++;
			if (str[i] == '.') // "%12." "%-1."
			{
				i++;
				if (str[i] == CONV(str[i])) // "%12.d" "%-1.d"
					return (1);
			}
			else if (str[i] == CONV(str[i]))// "%12s" "%-1d"
				return (1);
		}
		if (str[i] == '.') // "%1." "%-."
			if (str[i] == CONV(str[i]))
				return (1);
		if (str[i] == FLAG(str[i]))
		{
			i++;
			if (str[i] == CONV(str[i]))
				return (1);
		}
		i++;	
	}
	return (0);
}

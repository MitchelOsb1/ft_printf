/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:24:38 by mosborne          #+#    #+#             */
/*   Updated: 2018/02/12 18:17:02 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(char *str, int x)
{
	int i;

	i = 0;
	while (str[i] && i < x)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_postfix(char *str, int x)
{
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

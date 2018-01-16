/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:02:54 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/15 18:27:41 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

int	is_valid(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == CONV(str[i]))
			return (1);
		if (isdigit(str[i]) != | (str[i] == FLAG(str[i])))
			return (check_width(str, i));
		
}
}

char	*parse_form(char *str, va_list input)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 's')
			convert_s(str, i);
		i++;
	}
}

int	ft_printf(char const *restrict str, ...)
{
	char		*ret;
	static int	x = 0;
	va_list		input;

	va_start(input, str);
	while(str[x])
	{
		if (str[x] == '%' && is_valid(str, x))
		{
			ret = parse_form(str, input);
		}
		x++;
	}
	va_end(input);
	return (ret);
}

int	main(void)
{
	// ft_printf("%s", "Hello");
	printf("%s", "hello\n");
}

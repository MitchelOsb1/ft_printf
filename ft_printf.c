/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:02:54 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/12 16:48:03 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid(char *str)
{
	static int i = 0;

	if (str[i] == '%')
		i++;
	if (is_digit(str[i]))
		return (1);
	if (str[i] == CONV(str[i]))
		return (1);
	if (str[i] == FLAG(str[i]))
	{
		i++;
		if (is_digit(str[i]))
			return (1);
	}
	if (str[i] == '%')
		return (1);
}

char	*parse_form(char *str)
{
	while ()
	{
		if (str[i] == '')
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
		if (*str == '%' && is_valid(str[x]))
		{
			ret = parse_form(str);
		}
		x++;
	}
	va_end(input);
	return (ret);
}

int	main(void)
{
	ft_printf("%s", "Hello");
	printf("%s", "hello\n");
}

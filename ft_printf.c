/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:08 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/17 18:24:26 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void	init_tools(t_tools *format)
{
	format->minus = false;
	format->plus = false;
	format->space = false;
	format->hash = false;
	format->zero = false;
	format->star = false;
	format->width = 0;
	format->precision = 0;
	format->modifier = 0;
	format->str = 0;
	format->len = 0;
}

void	set_flags(char *str, int *x, va_list input)
{
	struct s_tools i;

	if (c == '-')
		i.minus = true;
	else if (c == '0')
		i.zero = true;
	else if (c == '+')
		i.plus = true;
	else if (c == ' ')
		i.space = true;
	else if (c == '#')
		i.hash = true;
}

void	set_width(char *str, int *x, va_list input)
{
	struct s_tools i;

	while (ft_isdigit(str[x]) != 0 | str[x] == '*' && str[x])
	{
		if (str[x] == '*')
			i.star = true;
		else if (ft_isdigit(str[x]) != 0)
		{
			i.width = va_arg(input, int);
			i.width = i.width * 10 + (str[x] - 48);
		}
		x++;
	}
}
	
void	set_prec(char *str, int *x, va_list input)
{
	struct s_tools i;

	while (str[x] && (str[x] == '.' || str[x] == '*' || ft_isdigit(str[x]) != 0))
	{
		if (str[x] == '.')
		{
			i++;
			if (str[x] == '*')
			{
				i.star = true;
				i.precision = (va_arg(input, int));
			}
			else if (ft_isdigit(str[x]) != 0)
			{
				i.precision = va_arg(input, int);
				i.precision = i.precision * 10 + (str[x] - 48);
			}
		}
		x++;
	}
}

char	*parse_form(char *str, char *ret, int *x, va_list input)
{
	print_prefix(str, x);
	while ((str[x] != '\0') && ((str[x] == OP(str[x])) | (str[x] == CONV(str[x])) |
	 (str[x] == MOD(str[x])) | (ft_isdigit(str[x]) == 1) | (str[x] == '.')))
	{
		set_flags(str, x, input);
		set_width(str, x); // Pass va_list 
		set_prec(str, x, input); // pass va_list
		x++;
	}
}

int	ft_printf(char const *restrict str, ...)
{
	char		*ret;
	static int	x = 0;
	va_list		input;
	t_tools		format;

	init_tools(&format);
	va_start(input, str);
	while (str[x])
	{
		if (str[x] == '%')
		{		
			ret = parse_form((char *)str, x, input);
		}
		x++;
	}
	printf("%5.1s\n", ret);
	va_end(input);
	return (1);
}

int	main(void)
{

	ft_printf("%s: %s", "hey", "Hello");
	printf("%s", "hello\n");
}

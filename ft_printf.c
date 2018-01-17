/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:02:54 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/16 19:09:41 by mosborne         ###   ########.fr       */
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
	format->ifprec = false;
	format->display = true;
	format->star = false;
	format->type = 0;
	format->width = 0;
	format->precision = 0;
	format->argument = 0;
	format->ret = 0;
	format->len = 0;
}

void	set_flags(char c, char *ret, int x)
{
	struct s_tools i;

	if (c == '-')
		i.minus=true;
	if (c == '0')
		i.zero=true;
	if (c == '+')
		i.plus=true;
	if (c == ' ')
		i.space=true;
	if (c == '#')
		i.hash=true;
}

void	set_width(char c)
{
	struct s_tools i;

	if (ft_isdigit(c))
		i.width *= c; // fix decimal val
}
	
void	set_prec(char *str, int x)
{
	if (str[x] == '.')
		{
			
		}
}

char	*parse_form(char *str, char *ret, int x)
{
	t_tools		format;

	init_tools(&format);
	while ((str[x] != '\0') && ((str[x] == FLAG(str[x])) | (str[x] == CONV(str[x])) |
	 (str[x] == MOD(str[x])) | (ft_isdigit(str[x]) == 1) | (str[x] == '.')))
	{
		set_flags(str[x]);
		set_width(str[x]); // Pass va_list 
		set_prec(str, x); // pass va_list
		x++;
	}
	return (str);
}

int	ft_printf(char const *restrict str, ...)
{
	char		*ret;
	static int	i = -1;
	static int	x = 0;
	va_list		input;

	va_start(input, str);
	while (str[x])
	{
		if (str[x] == '%')
			ret = parse_form((char *)str, x);
		if (str[x] == ',')
			print_arg(ret, str, x);
		x++;
	}
	printf("%5.1s\n", ret);
	va_end(input);
	return (1);
}

int	main(void)
{
	ft_printf("%s: %s", "HeY", "Hello");
	printf("\n%s", "hello\n");
}

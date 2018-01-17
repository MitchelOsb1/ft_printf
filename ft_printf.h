/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:02:57 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/16 19:11:07 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>

# define PLUS tools->plus
# define MINUS tools->minus
# define ZERO tools->zero
# define SPACE tools->spac
# define HASH tools->hash
# define IFPREC tools->ifprec
# define TYPE tools->type
# define WIDTH tools.width
# define PREC tools.precision
# define ARG tools.argument
# define RET tools.ret
# define LEN tools.len

typedef struct  s_tools
{
    bool    plus;
    bool    minus;
    bool    zero;
    bool    space;
    bool    hash;
    bool    ifprec;
    bool    display;
    bool    star;
    char    type;
    int     width;
    int     precision;
    int     argument;
    int     ret;
    int     len;
}               t_tools;

/* Spacing Flags */
# define FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')

/* Conversion Flags */
# define CONV(c) (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
    c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'x' || c == 'X' || \
    c == 'c' || c == 'C')

/* Modifier Flags */
# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'hh' || c == 'll')

#endif

/*
	while (f[*i] != '\0' && (f[*i] == '.' || f[*i] == '-' || f[*i] == '+' ||
			f[*i] == ' ' || f[*i] == '#' || f[*i] == '0' || f[*i] == '*' ||
			f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'j' || f[*i] == 'z' ||
			f[*i] == 'q' || (f[*i] >= '0' && f[*i] <= '9')))


** argument prototype: %[flags][width/margin][.precision][hh|h|l|ll|j|z]type
**
** flags:			'+' || '-' || ' ' || '#' || '0';
**
** width/margin:	min amount of displayed digits, does not cut digits if less,
**					fill with spaces on the left side;
**					if '*' added it's necessary to pass one more parameter with
**					a number of spaces before the actual parameter;
**
** .precision:		for diouxX min amount of digits, fill with 0 is necessary;
**					for eEf amount of digits after dot;
**					for gG amount of all digits, if bigger displays number;
**					for sS max amount of characters;
**					if '*' added is necessary to pass one more parameter with a
**					number of spaces before the actual parameter;
**
** hh|h|l|ll|j|z|q:	default values' modification:
**						hh:	for idouxX - char;
**						h:	for idouxX - short int;
**						l:	for idouxX - long int, for feE - double;
**						ll:	for idouxX - long long int;
**						j:	for idouxX - intmax_t;
**						z:	for idouxX - size_t;
**						q:	for CS - prints Unicode

*/
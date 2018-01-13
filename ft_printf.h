/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:02:57 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/12 16:48:20 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
    char    type;
    int     width;
    int     precision;
    int     argument;
    int     ret;
    int     len;
}               t_tools;

struct conversion[] = {
    {'s', &func},
    {'S', &func},
    
}

/* Spacing Flags */
# define FLAG(c) (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')

/* Conversion Flags */
# define CONV(c) (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
    c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'x' || c == 'X' || \
    c == 'c' || c == 'C')

/* Modifier Flags */
# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')

#endif

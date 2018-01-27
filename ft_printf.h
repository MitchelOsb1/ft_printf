/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:29 by mosborne          #+#    #+#             */
/*   Updated: 2018/01/26 13:05:27 by mosborne         ###   ########.fr       */
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
# define TYPE tools->type
# define WIDTH tools.width
# define PREC tools.precision
# define MODIFIER tools.modifier
# define STR tools.str
# define LEN tools.len

typedef struct  s_utils
{
    bool    plus;
    bool    minus;
    bool    zero;
    bool    space;
    bool    hash;
    int     width;
    int     precision;
    int     modifier;
    int     str;
    int     len;
}               t_utils;

/* Print Before Precent */
void	print_prefix(char *str, int x);

/* Setting Flags */
void	set_mods(char *str, int *x, t_utils *i);
void	set_flags(char *str, int *x, t_utils *i);
void	set_prec(char *str, int *x, t_utils *i);
void	set_conv(char *str, int *x, va_list input, t_utils *i);
void	set_width(char *str, int *x, t_utils *i);
void	parse_form(char *str, int *x, va_list input, t_utils *i);

/* Convert / Print Flags */
void	convert_char(t_utils *i, va_list input);

/* Tools */
char    *ins_w(char *str, int c, char t);

/*
    Modifier Flags
    0 = h
    1 = hh
    2 = l
    3 = ll
    4 = j
    5 = z
    6 = q
*/


#endif

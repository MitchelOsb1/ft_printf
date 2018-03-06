/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:29 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/06 11:36:16 by mosborne         ###   ########.fr       */
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
    bool        plus;
    bool        minus;
    bool        zero;
    bool        space;
    bool        hash;
    int         width;
    int         precision;
    int         modifier;
    int         buf;
    int         len;
    long int    i_nt;
}               t_utils;

/* Print Before Precent */
void	print_prefix(char *str, int x);
void	print_postfix(char *str, int x);

/* Setting Flags */
void	set_mods(char *str, int *x, t_utils *i);
void	set_flags(char *str, int *x, t_utils *i);
void	set_prec(char *str, int *x, t_utils *i);
void	set_conv(char *str, int *x, va_list input, t_utils *i);
void	set_width(char *str, int *x, t_utils *i);
void	parse_form(char *str, int *x, va_list input, t_utils *i);

/* Convert / Print Flags */
void	convert_string(t_utils *i, va_list input);
void    convert_int(t_utils *i, va_list input);

/* Tools */
void    s_wpl(t_utils *i, char cha_r);
char	h_mps(t_utils *i, char sign, long int x);
void	i_wpl(t_utils *i, char cha_r, int w);
void	i2_wpl(t_utils *i, char sign, int w);
void	i3_wpl(t_utils *i, char *str, char cha_r, int w);

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:29 by mosborne          #+#    #+#             */
/*   Updated: 2018/03/14 09:45:51 by mosborne         ###   ########.fr       */
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

typedef struct      s_utils
{
    bool            plus;
    bool            minus;
    bool            zero;
    bool            space;
    bool            hash;
    char            cha_r;
    int             width;
    int             precision;
    int             modifier;
    int             buf;
    int             len;
    int             count;
    long long int   i_nt;
}                   t_utils;

/* Printing */
void	print_prefix(char *str, int x, t_utils *i);
void	print_postfix(char *str, int x, t_utils *i);
void	print_hex_addr(unsigned long long int num, t_utils *i);

/* Setting Width/Precision/Len */
void	set_mods(char *str, int *x, t_utils *i);
void	set_flags(char *str, int *x, t_utils *i);
void	set_prec(char *str, int *x, t_utils *i);
void	set_conv(char *str, int *x, va_list input, t_utils *i);
void	set_width(char *str, int *x, t_utils *i);
void	parse_form(char *str, int *x, va_list input, t_utils *i);

/* Convert */
void	convert_string(t_utils *i, va_list input);
void    convert_int(t_utils *i, va_list input);
void	convert_char(t_utils *i, va_list input);
void	convert_unsigned_int(t_utils *i, va_list input);

/* Flag Sorting */
long long   i_mod(t_utils *i, va_list input);
long long   ui_mod(t_utils *i, va_list input);

/* Strings - Chars */
void    s_wpl(t_utils *i, char cha_r);
void	c_wpl(t_utils *i, unsigned char cha_r);

/* Int */
char	h_mps(t_utils *i, char sign, long int x);
void	i_wpl(t_utils *i, char cha_r, int w);
void	i2_wpl(t_utils *i, char sign, int w);
void	i3_wpl(t_utils *i, char *str, int w);
void    i4_wpl(t_utils *i, char cha_r, int w);

/* Unsigned Int */
void    o_wpl(t_utils *i, unsigned long int num);
void    u_wpl(t_utils *i, unsigned long int num);
void    x_wpl(t_utils *i, unsigned long int num);

/* Unsigned Int - Str Handle */
char    *c_octoa(unsigned long int num);
char    *c_hexoa(unsigned long int num, t_utils *i);
void    handl_ui(t_utils *i, unsigned long long int x);
void    print_ui(t_utils *i, unsigned long long int x, char *str);

/* Lib functions */
char    *ft_strrev(char *str);
char    *ft_ui_toa(unsigned int n);
char    *ft_ui_ll_toa(unsigned long long n);

/*
    Modifier Flags
    0 = h (short int) void*
    1 = hh (char) void*
    2 = l (long int) void*
    3 = ll (long long int) void*
    4 = j (intmax_t)
    5 = z (size_t)
    6 = q | d or i // (int) void*
*/


#endif

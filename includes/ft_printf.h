/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:27:29 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/02 10:19:50 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <wchar.h>

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

/*
**	0 = h (short int)
**	1 = hh (char)
**	2 = l (long int)
**	3 = ll (long long int)
**	4 = j (intmax_t)
**	5 = z (size_t)
**	6 = w (int)
*/

typedef struct			s_utils
{
	bool				plus;
	bool				minus;
	bool				zero;
	bool				space;
	bool				hash;
	char				cha_r;
	int					width;
	int					precision;
	int					modifier;
	int					buf;
	int					len;
	int					count;
	long long int		i_nt;
}						t_utils;

int						ft_printf(char const *restrict format, ...);
int						init_printf(char *str, va_list input, t_utils *i);

void					ft_putc_c(char c, int *cnt_ret);
void					ft_putc_s(char *str, int *cnt_ret);
void					print_prefix(char *str, int x, int y, t_utils *i);
void					print_postfix(char *str, int x, t_utils *i);
void					print_hex_addr(unsigned long long int num, t_utils *i);

void					set_mods(char *str, int *x, t_utils *i);
void					set_flags(char *str, int *x, t_utils *i);
void					set_prec(char *str, int *x, t_utils *i);
void					set_conv(char *str, int *x, va_list input, t_utils *i);
void					set_width(char *str, int *x, t_utils *i);
void					parse_form(char *str, int *x, va_list input, \
	t_utils *i);

void					convert_char(t_utils *i, va_list input);
void					convert_string(t_utils *i, va_list input);
void					convert_int(t_utils *i, va_list input);
void					convert_unsigned_int(t_utils *i, va_list input);
void					convert_point(t_utils *i, va_list input);

void					p_num(t_utils *i, unsigned long int x);
long long int			i_mod(t_utils *i, va_list input);
unsigned long long int	ui_mod(t_utils *i, va_list input);

void					s_wpl(t_utils *i, char cha_r);
void					c_wpl(t_utils *i, unsigned char cha_r);

char					h_mps(t_utils *i, char sign, long long int x);
void					i_wpl(t_utils *i, char cha_r, int w);
void					i2_wpl(t_utils *i, char sign, int w);
void					i3_wpl(t_utils *i, int w, long long int x);
void					i4_wpl(t_utils *i, char cha_r, int w);

void					o_wpl(t_utils *i, unsigned long int num);
void					u_wpl(t_utils *i, unsigned long int num);
void					x_wpl(t_utils *i, unsigned long int num);

void					handl_ui(t_utils *i, unsigned long long int x);
void					print_ui(t_utils *i, unsigned long long int x, \
	char *str);

void					handl_p(t_utils *i, char *str);
void					print_ptr_addr(t_utils *i);

void					convert_wchar(t_utils *i, va_list input);
void					handl_w_c(t_utils *i, va_list input);
void					handl_w_s(t_utils *i, va_list input);
void					handl_wp_c(t_utils *i, wchar_t wide);
void					handl_wp_s(t_utils *i, char *str);

void					convert_percent(t_utils *i);

char					*c_unitoa(wint_t wide);
char					*c_ptoa(unsigned long int num);
char					*c_octoa(unsigned long int num);
char					*c_hexoa(unsigned long int num, t_utils *i);

int						ft_isdigit(int c);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *s);
char					*ft_itoa(int n);
char					*ft_strcpy(char *s1, const char *s2);
char					*ft_strrev(char *str);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strnew(size_t size);
char					*ft_strdup(const char *str);
char					*ft_ui_toa(unsigned int n);
char					*ft_ui_ll_toa(unsigned long long int n);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_strdel(char **as);
void					ft_bzero(void *str, size_t n);
void					*ft_memset(void *str, int c, size_t n);
void					ft_putc_nbr(long long int num, int *int_cnt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 08:58:43 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/03 15:18:27 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_wchar(t_utils *i, va_list input)
{
	if (i->cha_r == 'C')
		handl_w_c(i, input);
	if (i->cha_r == 'S')
		handl_w_s(i, input);
}

void	handl_wc_c(t_utils *i, wchar_t wide)
{
	while (i->width-- > 0 && i->minus == 0)
		ft_putc_c(' ', &(i->count));
	ft_putc_s(c_unitoa(wide), &(i->count));
	while (i->width-- > 0 && i->minus == 1)
		ft_putc_c(' ', &(i->count));
}

void	handl_wc_s(t_utils *i, char *str)
{
	while (i->width-- > 0 && i->minus == 0)
		ft_putc_c(' ', &(i->count));
	if (i->precision != -69)
		ft_putc_s(str, &(i->count));
	while (i->width-- > -1 && i->minus == 1)
		ft_putc_c(' ', &(i->count));
}

void	handl_w_c(t_utils *i, va_list input)
{
	char	*str;
	wchar_t	wide;

	wide = va_arg(input, wint_t);
	str = c_unitoa(wide);
	i->len = ft_strlen(str);
	i->width -= i->len;
	handl_wc_c(i, wide);
	free(str);
}

void	handl_w_s(t_utils *i, va_list input)
{
	char	*str;
	wchar_t	*wide;

	wide = (wchar_t *)va_arg(input, wchar_t *);
	str = c_unitoa(*wide++);
	while (*wide != '\0')
		str = ft_strjoin(str, c_unitoa(*wide++));
	i->len = ft_strlen(str);
	if (i->precision == -69)
		i->len = 0;
	i->width -= i->len;
	handl_wc_s(i, str);
	free(str);
}

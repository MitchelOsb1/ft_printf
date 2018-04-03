/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uipw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:30:05 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/03 10:19:55 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*c_unitoa(wint_t wide)
{
	char	*str;

	str = ft_strnew(5);
	if (wide < 0x80)
		str[0] = ((wide >> 0) & 0x7F) | 0x00;
	else if (wide < 0x800)
	{
		str[0] = (((wide >> 6) & 0x1F) | 0xC0);
		str[1] = (((wide >> 0) & 0x3F) | 0x80);
	}
	else if (wide < 0x10000)
	{
		str[0] = (((wide >> 12) & 0x0F) | 0xE0);
		str[1] = (((wide >> 6) & 0x3F) | 0x80);
		str[2] = (((wide >> 0) & 0x3F) | 0x80);
	}
	else if (wide < 0x10FFFF)
	{
		str[0] = (((wide >> 18) & 0x07) | 0xF0);
		str[1] = (((wide >> 12) & 0x3F) | 0x80);
		str[2] = (((wide >> 6) & 0x3F) | 0x80);
		str[3] = (((wide >> 0) & 0x3F) | 0x80);
	}
	return (str);
}

char	*c_ptoa(unsigned long int num)
{
	unsigned int	x;
	char			str[12];
	char			*h_lower;

	x = 0;
	ft_bzero(str, 12);
	h_lower = "0123456789abcdef";
	if (num < x)
		return (0);
	if (num == 0)
		str[x++] = '0';
	while (num)
	{
		str[x++] = h_lower[num % 16];
		num = num / 16;
	}
	str[x] = '\0';
	return (ft_strrev(str));
}

char	*c_octoa(unsigned long int num)
{
	char			str[21];
	unsigned int	x;

	x = 0;
	ft_bzero(str, 21);
	if (num < x)
		return (0);
	if (num == 0)
		str[x++] = '0';
	while (num)
	{
		str[x++] = ((num % 8) + 48);
		num = num / 8;
	}
	str[x] = '\0';
	return (ft_strrev(str));
}

char	*c_hexoa(unsigned long int num, t_utils *i)
{
	char	str[21];
	char	*h_lower;
	char	*h_upper;
	int		x;

	x = 0;
	ft_bzero(str, 21);
	h_lower = "0123456789abcdef";
	h_upper = "0123456789ABCDEF";
	if (num == 0)
		str[x] = '0';
	if (i->cha_r == 'x')
		while (num)
		{
			str[x++] = h_lower[num % 16];
			num = num / 16;
		}
	if (i->cha_r == 'X')
		while (num)
		{
			str[x++] = h_upper[num % 16];
			num = num / 16;
		}
	return (ft_strrev(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunc3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:33:30 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/01 14:46:48 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;

	i = ft_strlen(s1);
	while (*s2 != '\0')
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *b;

	b = str;
	while (n--)
		*(unsigned char *)str++ = (unsigned char)c;
	return (b);
}

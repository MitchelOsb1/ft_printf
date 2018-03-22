/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:38:33 by mosborne          #+#    #+#             */
/*   Updated: 2017/09/25 19:24:19 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- > 0)
	{
		if (((char *)src)[i] == (char)c)
		{
			((char *)dst)[i] = ((char *)src)[i];
			return (&dst[i + 1]);
		}
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (NULL);
}

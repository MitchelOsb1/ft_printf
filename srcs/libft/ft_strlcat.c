/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:20:31 by mosborne          #+#    #+#             */
/*   Updated: 2017/10/05 19:09:37 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = ft_strlen(dst);
	while (dst[i])
		i++;
	if (size < i)
		return (ft_strlen((char *)src) + size);
	else
	{
		while (i < size - 1 && src[y])
			dst[i++] = src[y++];
	}
	dst[i] = '\0';
	return (x + ft_strlen((char *)src));
}

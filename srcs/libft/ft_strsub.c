/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:35:34 by mosborne          #+#    #+#             */
/*   Updated: 2017/10/04 16:45:46 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*x;

	i = 0;
	if (!s)
		return (0);
	if (!(x = (char *)malloc(len + 1)))
		return (0);
	while (len--)
	{
		x[i++] = s[start++];
	}
	x[i] = '\0';
	return (x);
}

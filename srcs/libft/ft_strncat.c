/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:33:58 by mosborne          #+#    #+#             */
/*   Updated: 2017/10/05 15:47:06 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t num)
{
	size_t	i;
	size_t	x;

	x = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while ((s2[x] != '\0') && (x < num))
	{
		s1[i] = s2[x];
		i++;
		x++;
	}
	s1[i] = '\0';
	return (s1);
}
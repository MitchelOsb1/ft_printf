/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 18:24:44 by mosborne          #+#    #+#             */
/*   Updated: 2017/09/26 14:40:39 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *i;

	i = s;
	i = i + ft_strlen(s);
	while (*i != (char)c && i != s)
		i--;
	if (*i == (char)c)
		return ((char *)i);
	return (NULL);
}

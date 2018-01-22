/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:16:53 by mosborne          #+#    #+#             */
/*   Updated: 2017/09/26 16:22:31 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int x;
	int i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		x = 0;
		while (big[i] == little[x] && big[i])
		{
			i++;
			x++;
		}
		if (!little[x])
			return ((char *)&big[i - x]);
		i = (i - x) + 1;
	}
	return (NULL);
}

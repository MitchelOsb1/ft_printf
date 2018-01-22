/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:44:51 by mosborne          #+#    #+#             */
/*   Updated: 2017/09/26 18:53:31 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*x;
	int		i;

	i = ft_strlen(str);
	x = (char *)malloc((i + 1) * sizeof(char));
	if (x)
		return (ft_strcpy(x, str));
	return (NULL);
}

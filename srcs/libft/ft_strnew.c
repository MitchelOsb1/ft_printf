/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:37:02 by mosborne          #+#    #+#             */
/*   Updated: 2017/10/04 16:41:56 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s1;

	if (!(s1 = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(s1, size + 1);
	return (s1);
}

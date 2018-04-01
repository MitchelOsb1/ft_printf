/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:29:33 by mosborne          #+#    #+#             */
/*   Updated: 2018/04/01 08:47:41 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *s1;

	if (!(s1 = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(s1, size + 1);
	return (s1);
}

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

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

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen((char *)s1) +
		ft_strlen((char *)s2) + 1)))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

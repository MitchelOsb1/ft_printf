/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:37:01 by mosborne          #+#    #+#             */
/*   Updated: 2017/10/10 13:40:05 by mosborne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *x;

	if (lst)
	{
		x = f(lst);
		x->next = ft_lstmap(lst->next, f);
		return (x);
	}
	return (NULL);
}

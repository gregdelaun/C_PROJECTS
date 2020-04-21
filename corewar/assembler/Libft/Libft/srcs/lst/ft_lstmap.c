/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:17:50 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/22 10:39:57 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *list;

	if (lst && f)
	{
		list = f(lst);
		new = list;
		while (lst->next)
		{
			lst = lst->next;
			if (!(list->next = f(lst)))
			{
				free(list->next);
				return (NULL);
			}
			list = list->next;
		}
		return (new);
	}
	return (NULL);
}

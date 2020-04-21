/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:53:03 by quroba            #+#    #+#             */
/*   Updated: 2018/11/28 15:05:55 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_clean(t_list **first, t_list *elem)
{
	t_list	*temp;

	while (*first != elem)
	{
		temp = (*first)->next;
		free((*first)->content);
		free(*first);
		*first = temp;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *first;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	elem = ft_lstnew(temp->content, temp->content_size);
	if (!elem)
		return (NULL);
	first = elem;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		elem->next = ft_lstnew(temp->content, temp->content_size);
		if (!elem->next)
		{
			ft_clean(&first, elem->next);
			return (NULL);
		}
		elem = elem->next;
		lst = lst->next;
	}
	return (first);
}

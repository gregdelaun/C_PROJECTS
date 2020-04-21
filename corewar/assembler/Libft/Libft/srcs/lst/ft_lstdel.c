/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:17:25 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/22 11:03:35 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && del)
	{
		while (*alst)
		{
			tmp = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = tmp;
		}
	}
	*alst = NULL;
}

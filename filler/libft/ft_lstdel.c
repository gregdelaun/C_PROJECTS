/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:52:24 by quroba            #+#    #+#             */
/*   Updated: 2018/11/29 13:14:01 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	if (!alst || !del || !(*alst))
		return ;
	while (*alst)
	{
		ptr = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = ptr;
	}
}

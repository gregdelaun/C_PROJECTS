/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:16:50 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/22 10:41:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nl;

	if ((nl = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		nl->content = NULL;
		nl->content_size = 0;
	}
	else
	{
		if ((nl->content = (char *)malloc(sizeof(content_size))) == NULL)
		{
			free(nl);
			return (NULL);
		}
		ft_memcpy((nl->content), content, content_size);
		nl->content_size = content_size;
	}
	nl->next = NULL;
	return (nl);
}

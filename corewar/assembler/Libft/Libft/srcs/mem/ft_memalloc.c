/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:17:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/13 13:19:54 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmem;

	if (((tmem = malloc(size)) == NULL) || size == 0)
		return (NULL);
	else
		return (ft_memset(tmem, 0, size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:09:13 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/15 09:52:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	temp;
	char	*temp2;

	i = 0;
	temp2 = (char *)str;
	temp = (char)c;
	while (i < n)
	{
		if (temp2[i] == temp)
			return (temp2 + i);
		i++;
	}
	return (NULL);
}

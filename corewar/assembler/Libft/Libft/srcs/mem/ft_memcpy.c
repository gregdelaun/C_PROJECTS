/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:40:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/19 14:43:56 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	const char		*temp2;

	i = 0;
	temp = (unsigned char *)str1;
	temp2 = str2;
	while (i < n)
	{
		temp[i] = temp2[i];
		i++;
	}
	return ((unsigned char *)str1);
}

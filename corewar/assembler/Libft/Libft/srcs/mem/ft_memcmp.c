/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:36:50 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/19 14:43:41 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tstr1;
	unsigned char	*tstr2;
	size_t			i;

	i = 0;
	tstr1 = (unsigned char *)str1;
	tstr2 = (unsigned char *)str2;
	while (i < n)
	{
		if (*(tstr1 + i) != *(tstr2 + i))
			return (tstr1[i] - tstr2[i]);
		i++;
	}
	return (0);
}

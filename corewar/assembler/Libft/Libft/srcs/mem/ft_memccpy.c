/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:22:06 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/19 14:44:37 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t		i;
	char		*temp;
	const char	*temp2;

	i = 0;
	temp = (char *)str1;
	temp2 = str2;
	while (i < n)
	{
		temp[i] = temp2[i];
		if (*((unsigned char *)str2 + i) == (unsigned char)c)
			return ((unsigned char *)str1 + i + 1);
		i++;
	}
	return (NULL);
}

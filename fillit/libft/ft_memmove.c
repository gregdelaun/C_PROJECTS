/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:54:53 by quroba            #+#    #+#             */
/*   Updated: 2018/11/27 13:43:09 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dest;
	i = 0;
	if (s1 == s2)
		return (dest);
	if (s1 > s2)
	{
		while (n > i)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	else
	{
		while (n--)
			s2[n] = s1[n];
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:53:45 by quroba            #+#    #+#             */
/*   Updated: 2018/11/29 13:08:47 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		n--;
		if ((*(unsigned char *)dest++ = *(unsigned char *)src++) ==
			(unsigned char)c)
			return ((void *)dest);
	}
	return (NULL);
}

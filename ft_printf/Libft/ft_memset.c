/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:55:06 by quroba            #+#    #+#             */
/*   Updated: 2018/11/26 13:55:08 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		n--;
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}

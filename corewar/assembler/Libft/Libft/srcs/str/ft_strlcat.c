/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:54:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/18 16:55:41 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (dest[i] && i < size)
			i++;
		j = i;
		while (src[i - j] && i < size - 1)
		{
			dest[i] = src[i - j];
			i++;
		}
	}
	if (j < size)
		dest[i] = '\0';
	return (ft_strlen(src) + j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_c0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:03:19 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:03:59 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat_c0(char *dest, const char *src, size_t n, int c)
{
	size_t i;
	size_t j;

	i = ft_strlen(dest);
	j = -1;
	while ((++j < n && src[j]) || c != 0)
	{
		if (src[j] == 0)
			c--;
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}

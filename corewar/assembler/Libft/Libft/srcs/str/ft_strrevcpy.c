/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:39:55 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/05 13:39:58 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrevcpy(char *dest, const char *src)
{
	int i;
	int j;

	i = ft_strlen(src) - 1;
	j = ft_strlen(dest) - 1;
	while (src[i])
	{
		dest[j] = src[i];
		i--;
		j--;
	}
	return (dest);
}

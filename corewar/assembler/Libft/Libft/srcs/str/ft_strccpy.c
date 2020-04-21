/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:40:18 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/10 13:40:19 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strccpy(char *dest, const char *src, int c)
{
	size_t i;

	i = 0;
	while (src[i] != c || src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

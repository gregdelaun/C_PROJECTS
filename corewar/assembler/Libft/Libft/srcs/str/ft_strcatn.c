/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:09:42 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/04 13:40:13 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strcatnl(char *dest, const char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = -1;
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = '\n';
	return (dest);
}

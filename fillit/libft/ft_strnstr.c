/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:01:45 by quroba            #+#    #+#             */
/*   Updated: 2018/11/29 12:35:44 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	if (!(ft_strlen(find)))
		return ((char *)str);
	while (*str && n >= ft_strlen(find))
	{
		n--;
		if (!(ft_strncmp(str, find, ft_strlen(find))))
			return ((char *)str);
		str++;
	}
	return ((char *)NULL);
}

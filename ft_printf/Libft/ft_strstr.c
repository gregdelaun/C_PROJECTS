/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:02:14 by quroba            #+#    #+#             */
/*   Updated: 2018/11/29 12:28:49 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	if (!(ft_strlen(find)))
		return ((char *)str);
	while (*str)
	{
		if (!(ft_strncmp(str, find, ft_strlen(find))))
			return ((char *)str);
		str++;
	}
	return ((char *)NULL);
}

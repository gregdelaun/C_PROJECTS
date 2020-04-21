/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:53:55 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/19 14:45:23 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	x;
	size_t	len;
	char	*temp;

	x = 0;
	len = ft_strlen(needle);
	temp = (char *)hay;
	if (!needle)
		return ((char *)hay);
	while (*hay && (x + len <= n))
	{
		if (ft_memcmp(hay, needle, len) == 0)
			return ((char *)hay);
		hay++;
		x++;
	}
	return (NULL);
}

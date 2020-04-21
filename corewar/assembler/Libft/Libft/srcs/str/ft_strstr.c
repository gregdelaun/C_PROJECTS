/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:53:55 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/13 16:12:41 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		x;
	int		c;
	char	*temp;

	x = 0;
	temp = (char *)haystack;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (temp[x])
	{
		c = 0;
		while (needle[c] == temp[c + x])
		{
			if (needle[c + 1] == '\0')
			{
				return (temp + x);
			}
			c++;
		}
		x++;
	}
	return (0);
}

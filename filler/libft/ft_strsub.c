/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:02:22 by quroba            #+#    #+#             */
/*   Updated: 2018/11/26 14:02:24 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = ft_strnew(len);
	i = 0;
	if (!sub)
		return (NULL);
	while (start)
	{
		start--;
		s++;
	}
	ft_strncpy(sub, s, len);
	sub[len] = '\0';
	return (sub);
}

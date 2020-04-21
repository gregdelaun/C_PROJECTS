/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 14:31:29 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/01 09:56:56 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		length;

	length = 0;
	i = 0;
	length = ft_strlen(src);
	str = ft_strnew(ft_strlen(src));
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

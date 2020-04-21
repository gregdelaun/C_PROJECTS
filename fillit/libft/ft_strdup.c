/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:58:37 by quroba            #+#    #+#             */
/*   Updated: 2018/11/29 12:14:53 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *tab;

	tab = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!(tab))
	{
		free(tab);
		return (NULL);
	}
	ft_strcpy(tab, s);
	return (tab);
}

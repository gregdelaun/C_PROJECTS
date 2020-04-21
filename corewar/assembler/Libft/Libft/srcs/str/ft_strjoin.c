/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:53:00 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/15 13:06:21 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tempcat;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		if ((tempcat = ft_strnew(i + j)) == NULL)
			return (NULL);
		else
		{
			ft_strcpy(tempcat, s1);
			return (tempcat = ft_strcat(tempcat, s2));
		}
	}
	return (NULL);
}

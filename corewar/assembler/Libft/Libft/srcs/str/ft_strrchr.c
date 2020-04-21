/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:34:30 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/15 16:46:02 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen((char *)str);
	while (str[i] != c && i > 0)
		i--;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

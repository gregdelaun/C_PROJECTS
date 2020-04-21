/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:30:10 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/15 09:54:55 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&str[i]);
	if (str[i] != '\0')
		return ((char *)&str[i]);
	else
		return (NULL);
}

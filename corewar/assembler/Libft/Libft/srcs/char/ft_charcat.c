/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:40:40 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/02 12:40:41 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_charcat(char *dest, const char src)
{
	int i;

	i = ft_strlen(dest);
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}

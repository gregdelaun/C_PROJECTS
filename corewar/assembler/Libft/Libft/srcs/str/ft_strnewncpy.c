/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:40:54 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/10 13:40:55 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnewncpy(int len, char *src)
{
	char *str;

	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strncpy(str, src, len);
	return (str);
}

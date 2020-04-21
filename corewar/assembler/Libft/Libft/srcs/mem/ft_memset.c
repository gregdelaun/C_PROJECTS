/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:06:36 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/19 14:44:58 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)str;
	while (n--)
	{
		temp[i] = (char)c;
		i++;
	}
	return (str);
}

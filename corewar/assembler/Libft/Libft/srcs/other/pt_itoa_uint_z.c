/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_uint_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:09:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:09:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*pt_itoa_uint_z(size_t n, char *temp)
{
	intmax_t	nb;
	int			length;

	nb = n;
	length = ft_divlen_ul(n, 10);
	while (--length >= 0)
	{
		temp[length] = nb % 10 + '0';
		nb /= 10;
	}
	temp[ft_strlen(temp) + 1] = '\0';
	return (temp);
}

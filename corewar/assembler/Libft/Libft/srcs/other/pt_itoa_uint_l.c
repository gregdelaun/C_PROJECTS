/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_uint_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:56:47 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:56:48 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*pt_itoa_uint_l(unsigned long n, char *temp)
{
	unsigned long	nb;
	int				length;

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

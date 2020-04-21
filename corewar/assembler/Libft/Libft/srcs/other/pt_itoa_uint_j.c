/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_uint_j.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:56:31 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:56:32 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*pt_itoa_uint_j(uintmax_t n, char *temp)
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

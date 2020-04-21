/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:30:08 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:56:56 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*pt_itoa_uint(unsigned int n, char *temp)
{
	unsigned int	nb;
	int				length;
	int				neg;

	if ((long)n < 0)
		neg = -1;
	else
		neg = 1;
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

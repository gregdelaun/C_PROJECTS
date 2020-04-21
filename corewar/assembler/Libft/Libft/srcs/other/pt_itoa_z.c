/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:57:05 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:57:06 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		isneg(size_t *nb, int *negative)
{
	if ((long long int)*nb < 0)
	{
		*nb *= -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

char			*pt_itoa_z(size_t n, char *temp)
{
	size_t	nb;
	int		length;
	int		negative;

	nb = n;
	isneg(&nb, &negative);
	length = ft_divlen(nb, 10);
	if (negative == 1)
		length++;
	while (--length >= 0)
	{
		temp[length] = nb % 10 + '0';
		nb /= 10;
	}
	if (negative == 1)
		temp[0] = '-';
	temp[ft_strlen(temp) + 1] = '\0';
	return (temp);
}

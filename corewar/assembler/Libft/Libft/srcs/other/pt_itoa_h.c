/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:55:56 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:55:57 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		isneg(int *nb, int *negative)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

char			*pt_itoa_h(short n, char *temp)
{
	int	nb;
	int	length;
	int	negative;

	nb = n;
	isneg(&nb, &negative);
	length = ft_divlen(nb, 10);
	if (n < 0)
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

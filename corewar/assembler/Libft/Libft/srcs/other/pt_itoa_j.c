/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:56:05 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:56:06 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		isneg(intmax_t *nb, int *negative)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

char			*pt_itoa_j(intmax_t n, char *temp)
{
	intmax_t	nb;
	int			length;
	int			negative;

	if (n < -9223372036854775807)
	{
		temp = ft_strcpy(temp, "-9223372036854775808");
		return (temp);
	}
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

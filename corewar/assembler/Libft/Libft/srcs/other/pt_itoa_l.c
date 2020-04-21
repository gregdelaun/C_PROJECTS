/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_itoa_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:56:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:56:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		isneg(long *nb, int *negative)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*negative = 1;
	}
	else
		*negative = 0;
}

char			*pt_itoa_l(long n, char *temp)
{
	long	nb;
	int		length;
	int		negative;

	if (n < -9223372036854775807)
	{
		temp = ft_strcpy(temp, "-9223372036854775808");
		return (temp);
	}
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

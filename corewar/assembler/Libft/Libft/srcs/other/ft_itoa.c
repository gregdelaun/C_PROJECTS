/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:22:36 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/16 10:51:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		isneg(long *nb, int *negative, int *length)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*negative = 1;
		*length = 2;
	}
	else
	{
		*negative = 0;
		*length = 1;
	}
}

static void		reset(long *nb, int negative)
{
	if (negative == 1)
		*nb *= -1;
}

char			*ft_itoa(int n)
{
	long	nb;
	int		length;
	int		negative;
	char	*temp;

	nb = n;
	isneg(&nb, &negative, &length);
	while (nb /= 10)
		length++;
	nb = n;
	reset(&nb, negative);
	if ((temp = ft_strnew(length)) == NULL)
		return (NULL);
	while (length--)
	{
		temp[length] = nb % 10 + '0';
		nb /= 10;
	}
	if (negative == 1)
		temp[0] = '-';
	temp[ft_strlen(temp) + 1] = '\0';
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:51:54 by quroba            #+#    #+#             */
/*   Updated: 2018/11/27 13:59:36 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countdigit(long n)
{
	size_t i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	long	n_long;
	size_t	c;
	char	neg;

	n_long = n;
	c = ft_countdigit(n);
	neg = (n_long < 0 ? 1 : 0);
	str = ft_strnew(c + neg);
	if (!(str))
		return (NULL);
	if (neg)
	{
		n_long = -n_long;
		str[0] = '-';
	}
	while (c > 0)
	{
		str[c + neg - 1] = (n_long % 10) + '0';
		c--;
		n_long = n_long / 10;
	}
	return (str);
}

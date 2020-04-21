/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:04:08 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 11:05:01 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_power(int val, int pow)
{
	uintmax_t	ret;

	ret = 1;
	while (pow-- > 0)
		ret *= val;
	return (ret);
}

char	*place_decimal(int i, char *ret, uintmax_t dec)
{
	while (i > -1)
	{
		ret[i--] = (dec % 10) + '0';
		dec /= 10;
	}
	return (ret);
}

int		check_frac(uintmax_t frac)
{
	if (frac == 1)
		return (1);
	if (frac == 10)
		return (1);
	if (frac == 100)
		return (1);
	if (frac == 1000)
		return (1);
	if (frac == 10000)
		return (1);
	if (frac == 100000)
		return (1);
	if (frac == 1000000)
		return (1);
	if (frac == 10000000)
		return (1);
	if (frac == 100000000)
		return (1);
	if (frac == 1000000000)
		return (1);
	return (0);
}

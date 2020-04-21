/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:03:10 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 13:08:17 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int n)
{
	long temp;

	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		ft_putchar('-');
	}
	if (temp >= 0 && temp < 10)
		ft_putchar(temp + '0');
	else if (temp >= 10)
	{
		ft_putnbr(temp / 10);
		ft_putchar((temp % 10) + '0');
	}
}

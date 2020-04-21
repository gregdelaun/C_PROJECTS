/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:56:21 by quroba            #+#    #+#             */
/*   Updated: 2019/06/03 15:45:30 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(intmax_t n)
{
	intmax_t			i;
	unsigned long long	g;

	g = 9223372036854775808U;
	i = n;
	if ((unsigned long long)i == g)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (i < 0)
	{
		ft_putnbr(-i);
	}
	else if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar((i % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

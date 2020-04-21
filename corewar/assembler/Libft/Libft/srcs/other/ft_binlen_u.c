/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:15:48 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:15:51 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_binlen_u(unsigned long int n)
{
	int i;

	if ((long long int)n < 0)
	{
		n *= -1;
		i = 0;
		while (n)
		{
			n /= 2;
			i++;
		}
		return (i - (i % 4));
	}
	else if (n <= 15)
		return (4);
	else if (n <= 255)
		return (8);
	else if (n <= 4095)
		return (12);
	else if (n <= 65535)
		return (16);
	else if (n <= 524295)
		return (20);
	return (1);
}

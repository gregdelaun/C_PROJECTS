/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:17:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:15:21 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_binlen(long n)
{
	int i;

	if (n < 0)
	{
		n *= -1;
		i = 0;
		while (n)
		{
			n /= 2;
			i++;
		}
		return (i);
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

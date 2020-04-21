/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexavalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:18:18 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:16:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	ft_hexavalue(unsigned long int rem, char *hexa, int l)
{
	char	temp;
	int		j;

	temp = 'a';
	j = 10;
	if (rem <= 9)
	{
		hexa[l] = rem + '0';
		return (hexa[l]);
	}
	else
	{
		while (j < (int)rem)
		{
			temp++;
			j++;
		}
		hexa[l] = temp;
		return (hexa[l]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_bintohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:54:13 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:54:14 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*bintohexconv(char *hexa, char *temp)
{
	int l;
	int i;
	int val;
	int j;

	l = 4;
	val = 0;
	j = 0;
	while (l <= (int)ft_strlen(temp))
	{
		i = 1;
		while (i <= 4)
		{
			if (temp[l - i] == '1')
				val += ft_inttopower(2, i - 1);
			i++;
		}
		hexa[j] = ft_hexavalue(val, temp, j);
		j++;
		val = 0;
		l += 4;
	}
	return (hexa);
}

char		*pt_bintohex(char *hexa, char *temp)
{
	bintohexconv(hexa, temp);
	ft_strclr(temp);
	return (hexa);
}

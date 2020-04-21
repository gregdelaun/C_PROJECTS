/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_inttohexastr_ll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:52:28 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:52:30 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*neghex(unsigned long long deci, char *hexa, char *temp)
{
	int		i;

	temp = pt_dectobin_l(deci, temp);
	hexa = pt_bintohex(hexa, temp);
	ft_strclr(temp);
	i = 0;
	while (i < 8)
	{
		temp[i] = 'f';
		i++;
	}
	temp = ft_strcat(temp, hexa);
	hexa = ft_strcpy(hexa, temp);
	return (hexa);
}

static char	*poshex(unsigned long long deci, char *hexa)
{
	int		l;

	l = ft_divlen(deci, 16);
	l--;
	while (l >= 0)
	{
		hexa[l] = ft_hexavalue(deci % 16, hexa, l);
		deci /= 16;
		l--;
	}
	return (hexa);
}

/*
** This function will convert an int to a hexadecimal value in the form
** of a char*. If the second int parameter equals 0 it will just return
** the calculated value, if it is 1 it will add 0x in front of the result
*/

char		*pt_inttohexastr_ll(unsigned long long d, int i, char *h, char *t)
{
	if ((long long)d < 0)
		h = neghex(d, h, t);
	else if (d == 0)
		h[0] = '0';
	else
		h = poshex(d, h);
	if (i == 1 && d != 0)
	{
		pt_strrot(&h, 2);
		h[0] = '0';
		h[1] = 'x';
	}
	return (h);
}

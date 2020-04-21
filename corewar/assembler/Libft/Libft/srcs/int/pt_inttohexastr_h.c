/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_inttohexastr_h.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:52:41 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:52:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*neghex(unsigned short deci, char *h, char *temp)
{
	int		l;
	int		i;

	temp = pt_dectobin(deci, temp);
	h = pt_bintohex(h, temp);
	l = ft_strlen(h);
	if (l < 8)
	{
		i = 0;
		while (i + l < 8)
		{
			temp[i] = 'f';
			i++;
		}
		temp = ft_strcat(temp, h);
		h = ft_strcpy(h, temp);
		return (h);
	}
	else
		return (h);
}

static char	*poshex(unsigned short deci, char *h)
{
	int		l;

	l = ft_divlen(deci, 16);
	l--;
	while (l >= 0)
	{
		h[l] = ft_hexavalue(deci % 16, h, l);
		deci /= 16;
		l--;
	}
	return (h);
}

/*
** This function will convert an int to a hexadecimal value in the form
** of a char*. If the second int parameter equals 0 it will just return
** the calculated value, if it is 1 it will add 0x in front of the result
*/

char		*pt_inttohexastr_h(unsigned short deci, int i, char *h, char *temp)
{
	if ((int)deci < 0)
		h = neghex(deci, h, temp);
	else if (deci == 0)
		h[0] = '0';
	else
		h = poshex(deci, h);
	if (i == 1 && deci != 0)
	{
		pt_strrot(&h, 2);
		h[0] = '0';
		h[1] = 'x';
	}
	return (h);
}

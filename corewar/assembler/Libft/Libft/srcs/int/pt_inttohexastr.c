/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_inttohexastr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:52:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:52:15 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*neghex(unsigned int deci, char *hexa, char *temp)
{
	int		l;
	int		i;

	temp = pt_dectobin(deci, temp);
	hexa = pt_bintohex(hexa, temp);
	l = ft_strlen(hexa);
	if (l < 8)
	{
		i = 0;
		while (i + l < 8)
		{
			temp[i] = 'f';
			i++;
		}
		temp = ft_strcat(temp, hexa);
		hexa = ft_strcpy(hexa, temp);
		return (hexa);
	}
	else
		return (hexa);
}

static char	*poshex(unsigned int deci, char *hexa)
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

char		*pt_inttohexastr(unsigned int deci, int i, char *hexa, char *temp)
{
	if ((long)deci < 0)
		hexa = neghex(deci, hexa, temp);
	else if (deci == 0)
		hexa[0] = '0';
	else
		hexa = poshex(deci, hexa);
	if (i == 1 && deci != 0)
	{
		pt_strrot(&hexa, 2);
		hexa[0] = '0';
		hexa[1] = 'x';
	}
	return (hexa);
}

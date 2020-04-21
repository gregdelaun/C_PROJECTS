/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scinot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:41:26 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:14:32 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*fillout(int len, char *temp, char *temp2)
{
	if (len < 10)
	{
		temp = ft_strcat(temp, "e+0");
		temp = ft_strcat(temp, pt_itoa(len, temp2));
	}
	else
	{
		temp = ft_strcat(temp, "e+");
		temp = ft_strcat(temp, pt_itoa(len, temp2));
	}
	return (temp);
}

static char		*shortenout(char *temp)
{
	ft_charswap(&temp[0], &temp[1]);
	pt_strrot(&temp, -1);
	temp[ft_strlen(temp) - 1] = '\0';
	return (temp);
}

char			*ft_scinot(double n, int after, char *temp, char *temp2)
{
	double	tempn;
	int		len;

	tempn = n;
	len = ft_divlen(tempn, 10);
	while (--len)
		tempn /= 10;
	temp = pt_ftoa(tempn, after, temp, temp2);
	ft_strclr(temp2);
	tempn = n;
	len = ft_divlen(tempn, 10) - 1;
	if (ft_strlen_c(temp, '.') > 1)
	{
		temp = shortenout(temp);
		len++;
	}
	temp = fillout(len, temp, temp2);
	return (temp);
}

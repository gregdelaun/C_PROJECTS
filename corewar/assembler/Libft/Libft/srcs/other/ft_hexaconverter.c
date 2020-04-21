/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconverter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:38:22 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/12 11:11:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		hexavalue(char str)
{
	int		i;
	char	j;

	i = 1;
	j = 'A';
	if (!(str))
		return (0);
	if (ft_isdigit(str))
		return (str - '0');
	if ((str >= 'A' && str <= 'F') || (str >= 'a' && str <= 'f'))
	{
		if (str >= 'a' && str <= 'f')
			str -= 32;
		while (j != str)
		{
			j++;
			i++;
		}
		return (9 + i);
	}
	return (0);
}

int				ft_hexaconverter(char *str)
{
	int		deci;
	int		base;
	int		i;

	if (!(str))
		return (0);
	i = 0;
	if (str[0] == 0 && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	deci = 0;
	i = ft_strlen(str);
	i--;
	base = 1;
	while (i >= 0)
	{
		deci += hexavalue(str[i]) * base;
		i--;
		base *= 16;
	}
	return (deci);
}

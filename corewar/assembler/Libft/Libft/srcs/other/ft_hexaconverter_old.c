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

#include "../includes/get_next_line.h"

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

static char		*hexaconv(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			if (!(temp = ft_strnew(ft_strlen(&str[i + 1]))))
				return (NULL);
			return (ft_strcpy(temp, &str[i + 1]));
		}
		i++;
	}
	return (NULL);
}

int				ft_hexaconverter_old(char *str)
{
	int		deci;
	int		base;
	int		i;
	char	*temp;

	if (!(str))
		return (255);
	if (!(temp = hexaconv(str)))
		return (255);
	i = 0;
	if (str[0] == 0 && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	deci = 0;
	i = ft_strlen(temp);
	i--;
	base = 1;
	while (i >= 0)
	{
		deci += hexavalue(temp[i]) * base;
		i--;
		base *= 16;
	}
	ft_strdel(&temp);
	return (deci);
}

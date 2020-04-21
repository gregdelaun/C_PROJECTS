/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 09:59:45 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/18 09:59:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static double	after(char *temp)
{
	int		digit;
	double	a;
	int		i;
	int		len;

	len = 1;
	i = 0;
	a = 0;
	while (temp[i] != '.')
		i++;
	i++;
	while (ft_isdigit(temp[i]))
	{
		digit = temp[i] - '0';
		if (digit > 9 || digit < 0)
			break ;
		a = (a * 10) + digit;
		i++;
		len *= 10;
	}
	return (a / len);
}

static int		before(char *temp)
{
	int digit;
	int	b;
	int i;

	i = 0;
	b = 0;
	while (temp[i] != '.' || temp[i] != '\0' || temp[i] != ' ')
	{
		digit = temp[i] - '0';
		if (digit > 9 || digit < 0)
			break ;
		b = (b * 10) + digit;
		i++;
	}
	return (b);
}

static double	convert(char *temp)
{
	double	final;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (temp[i] == ' ' || temp[i] == '\f' || temp[i] == '\n'
			|| temp[i] == '\r' || temp[i] == '\t' || temp[i] == '\v')
		i++;
	if (temp[i] == '-')
	{
		sign = -1;
		i++;
	}
	final = before(&temp[i]) + after(&temp[i]);
	return (final * sign);
}

double			ft_atof(const char *str)
{
	char	*temp;
	double	final;

	temp = (char *)str;
	final = convert(temp);
	return (final);
}

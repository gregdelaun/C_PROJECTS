/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:17:07 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/22 14:51:25 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	isnegative(char c, int *sign)
{
	if (c == '-')
		*sign = -1;
	else
		*sign = 1;
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	char	*temp;
	int		digit;

	i = 0;
	temp = (char *)str;
	while (*temp == ' ' || *temp == '\f' || *temp == '\n'
			|| *temp == '\r' || *temp == '\t' || *temp == '\v')
		temp++;
	isnegative(*temp, &sign);
	if (sign == -1)
		temp++;
	else if (*temp == '+')
		temp++;
	while (*temp != '\0')
	{
		digit = *temp - '0';
		if (digit > 9 || digit < 0)
			break ;
		i = (i * 10) + digit;
		temp++;
	}
	return ((int)(i * sign));
}

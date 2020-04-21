/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:50:04 by quroba            #+#    #+#             */
/*   Updated: 2019/06/03 15:47:20 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_limit(intmax_t *res, int sign)
{
	if (sign == 1 && *res > 9223372036854775807)
		*res = -1;
	if (sign == -1 && *res > 9223372036854775807)
		*res = 0;
	return (*res);
}

int			ft_atoi(const char *str)
{
	intmax_t	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == '\f' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		sign = sign * (-1);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res = (res * 10 + (*str - '0'));
		str++;
	}
	ft_limit(&res, sign);
	return ((int)res * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_intoctal_j.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 09:55:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 09:57:21 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*pt_intoctal_j(uintmax_t input, char *temp)
{
	int	len;

	len = ft_divlen_ul(input, 8);
	while (--len >= 0)
	{
		temp[len] = input % 8 + '0';
		input /= 8;
	}
	return (temp);
}

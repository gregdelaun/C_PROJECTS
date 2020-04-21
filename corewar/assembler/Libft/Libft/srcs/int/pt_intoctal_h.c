/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_intoctal_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 09:54:35 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 09:56:59 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*pt_intoctal_h(unsigned short int input, char *temp)
{
	int	len;

	len = ft_divlen(input, 8);
	while (--len >= 0)
	{
		temp[len] = input % 8 + '0';
		input /= 8;
	}
	return (temp);
}

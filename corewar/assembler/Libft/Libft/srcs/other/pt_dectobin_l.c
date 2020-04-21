/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_dectobin_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:54:33 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:54:35 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*pt_dectobin_l(unsigned long int n, char *temp)
{
	unsigned long int	tmpn;
	int					len;
	int					isneg;

	if ((long long int)n < 0)
		isneg = -1;
	else
		isneg = 1;
	tmpn = n;
	len = ft_binlen_u(tmpn);
	while (--len >= 0)
	{
		temp[len] = tmpn % 2 + '0';
		tmpn /= 2;
	}
	if (isneg == -1)
		temp = ft_reversebin(temp);
	return (temp);
}

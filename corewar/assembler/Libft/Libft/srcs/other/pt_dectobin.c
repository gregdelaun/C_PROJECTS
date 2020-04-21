/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:54:44 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:54:45 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*pt_dectobin(int n, char *temp)
{
	int		tmpn;
	int		len;
	int		isneg;

	if (n < 0)
		isneg = -1;
	else
		isneg = 1;
	tmpn = n * isneg;
	len = ft_binlen(tmpn);
	while (--len >= 0)
	{
		temp[len] = tmpn % 2 + '0';
		tmpn /= 2;
	}
	if (isneg == -1)
		temp = ft_reversebin(temp);
	return (temp);
}

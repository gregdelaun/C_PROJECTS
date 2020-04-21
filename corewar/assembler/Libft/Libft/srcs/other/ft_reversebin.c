/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversebin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:30:11 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/27 12:30:12 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_reversebin(char *bin)
{
	int l;

	l = ft_strlen(bin) - 1;
	while (bin[l] != '1' && l >= 0)
		l--;
	while (--l >= 0)
	{
		if (bin[l] == '0')
			bin[l]++;
		else if (bin[l] == '1')
			bin[l]--;
	}
	return (bin);
}

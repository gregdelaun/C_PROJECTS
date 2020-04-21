/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:48:49 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/15 09:53:12 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char *tstr;
	char *tstr2;

	tstr = (char *)str1;
	tstr2 = (char *)str2;
	if (tstr2 < tstr)
	{
		tstr = tstr + n - 1;
		tstr2 = tstr2 + n - 1;
		while (n--)
			*tstr-- = *tstr2--;
	}
	else
	{
		while (n--)
			*tstr++ = *tstr2++;
	}
	return (str1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:15:51 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/01/28 11:18:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_intarrclr(int **ap, int y)
{
	if (ap && *ap)
	{
		while (--y >= 0)
			ft_memdell(ap[y]);
		free(ap);
		ap = NULL;
	}
	if (ap)
		free(ap);
}

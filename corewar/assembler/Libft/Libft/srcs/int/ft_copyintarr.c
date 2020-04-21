/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyintarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:28:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/21 10:49:35 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	*ft_copyintarr(int size, int *new, int *old)
{
	int i;

	i = 0;
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}

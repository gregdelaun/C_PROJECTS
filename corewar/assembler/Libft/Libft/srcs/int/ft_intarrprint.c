/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:34:25 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/07 15:38:19 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_intarrprint(int **arr, int max_x, int max_y)
{
	int i;
	int j;

	j = 0;
	while (j < max_y)
	{
		i = 0;
		while (i < max_x)
		{
			ft_putnbr(arr[j][i]);
			if (i + 1 != max_x)
				ft_putstr(", ");
			i++;
		}
		ft_putendl("");
		j++;
	}
}

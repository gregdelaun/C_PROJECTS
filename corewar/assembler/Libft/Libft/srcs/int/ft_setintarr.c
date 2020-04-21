/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setintarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:27:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/21 10:49:51 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	*ft_setintarr(int size, int set_value, int *arr)
{
	int i;

	i = -1;
	while (++i < size)
		arr[i] = set_value;
	return (arr);
}

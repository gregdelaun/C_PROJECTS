/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:29:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/21 10:50:34 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	*ft_intarr(int size, int start_value)
{
	int *arr;
	int i;

	i = 0;
	if (!(arr = ft_memalloc(sizeof(int) * (size + 1))))
		return (NULL);
	arr = ft_setintarr(size + 1, start_value, arr);
	return (arr);
}

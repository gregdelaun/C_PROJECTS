/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttopower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:30:50 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/21 12:30:52 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_inttopower(int n, int power)
{
	int i;

	i = n;
	if (power == 0)
		return (1);
	while (--power > 0)
		n *= i;
	return (n);
}

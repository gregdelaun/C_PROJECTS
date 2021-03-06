/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:02:32 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:03:44 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlen_c0(const char *str, int c0)
{
	size_t i;

	i = 0;
	while (str[i] || c0 != 0)
	{
		if (str[i] == '\0' && c0 != 0)
			c0--;
		i++;
	}
	return (i);
}

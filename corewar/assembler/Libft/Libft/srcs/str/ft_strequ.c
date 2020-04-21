/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:40:24 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/05 12:47:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		i = ft_strcmp(s1, s2);
		if (i == 0)
			return (1);
		else
			return (0);
	}
	return ((int)NULL);
}

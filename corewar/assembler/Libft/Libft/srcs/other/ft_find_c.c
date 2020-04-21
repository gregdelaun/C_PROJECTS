/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:49:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/21 10:49:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**	searches variable c within the line
**	returns 1 if found
**	returns 0 if not found
*/

int		ft_find_c(char *line, char c)
{
	int	x;

	x = -1;
	while (line[++x])
		if (line[x] == c)
			return (1);
	return (0);
}

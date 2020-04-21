/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conn_amount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:28:26 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/21 10:50:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
**	checks if the matrix is a square or not
*/

static int	check_square(char **matrix)
{
	int	i;
	int	j;
	int	x;

	if (!matrix || !*matrix)
		return (-1);
	i = ft_strlen(matrix[0]);
	j = -1;
	while (matrix[++j])
	{
		x = ft_strlen(matrix[j]);
		if (x != i)
			return (-1);
	}
	if (j != i)
		return (-1);
	return (1);
}

/*
**  conn_amount calculates the matrix to the 2nd power (matrix^2)
**  and returns the value of the amount of connections per point in the matrix
*/

int			ft_conn_amount(char **matrix, int line)
{
	int i;
	int conn;

	i = -1;
	conn = 0;
	if ((check_square(matrix)) == -1)
		return (-1);
	while (matrix[line][++i])
		if (matrix[line][i] == '1')
			conn++;
	return (conn);
}

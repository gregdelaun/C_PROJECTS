/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:33:06 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/07/10 14:33:07 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
** Checks if a certain character is placed in the column
*/

static int	check_column(char **map, int x, int c)
{
	int y;

	y = 0;
	while (map[y])
	{
		if (map[y][x] == c)
			return (1);
		y++;
	}
	return (0);
}

/*
**	Gets the actual token size based on the positions of
**	'*' within the token
*/

void		get_token_size(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
		*x += check_column(map, i, '*');
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '*')
			{
				*y += 1;
				if (map[j + 1] != NULL)
					j++;
				else
					break ;
				i = -1;
			}
		}
	}
}

/*
**	Copies the strings in which a '*' is placed.
**	sy = starting y
**	ft_strncpy is used to copy the total width of the piece
*/

static char	**make_new_token(char **input, char **new, int sy)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	get_token_size(input, &x, &y);
	while (check_column(input, i, '*') == 0)
		i++;
	j = 0;
	while (j < y)
	{
		new[j] = ft_strncpy(new[j], &input[sy][i], x);
		sy++;
		j++;
	}
	return (new);
}

/*
**	Searches the first occuring '*'
*/

static int	first_pos(char **input)
{
	int	x;
	int	y;

	y = 0;
	while (input[y])
	{
		x = 0;
		while (input[y][x])
		{
			if (input[y][x] == '*')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

/*
**	Starts making the optimized token
*/

char		**make_opti_token(char **input, char **new_token)
{
	int	tx;
	int	ty;

	tx = 0;
	ty = 0;
	get_token_size(input, &tx, &ty);
	new_token = make_new_token(input, new_token, first_pos(input));
	return (new_token);
}

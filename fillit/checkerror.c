/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:32:52 by quroba            #+#    #+#             */
/*   Updated: 2019/05/07 12:15:30 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_error2(char *temp, int i)
{
	if ((temp[i] != '.' && temp[i] != '#' && temp[i] != '\n')
		|| ((i % 5 == 0) && (temp[(i - 1)] != '\n') && (i != 0)))
		return (1);
	if ((i % 20 == 0) && (i != 0))
	{
		if (temp[i] != '\n')
			return (1);
		if (temp[i + 1] == '\0')
			return (2);
	}
	return (0);
}

int	check_error(char *temp, int c, int b)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if ((check_error2(temp, i)) == 1)
		{
			fre(temp, b, c);
			return (1);
		}
		if ((check_error2(temp, i)) == 2)
			break ;
		if ((i % 20 == 0) && (i != 0))
		{
			fre(temp, b, c);
			if ((temp = ft_strsub(temp, (i + 1), (c - i))) == NULL)
				return (1);
			c = c - i;
			i = -1;
		}
		i++;
	}
	fre(temp, b, c);
	return (0);
}

int	count_hashtag(char *temp)
{
	int c;
	int b;

	c = 0;
	b = 0;
	while (temp[c])
	{
		if (temp[c] == '#')
			b++;
		c++;
	}
	if ((b / 4) != g_nbr_tetrimonis || b % 4 != 0)
		return (1);
	return (0);
}

int	check_valid_tetri(char **tab)
{
	int i;
	int j;
	int c;

	i = 0;
	while (tab[i])
	{
		c = 0;
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				if (check(i, j, tab) == 0)
					c = c + 1;
				else if (check(i, j, tab) == 2)
					c = c + 2;
			}
			j++;
		}
		if (c < 2)
			return (1);
		i++;
	}
	return (0);
}

int	check(int i, int j, char **tab)
{
	if (tab[i][j + 1] == '#' && tab[i][j - 1] == '#' && tab[i][j + 5] == '#')
		return (2);
	if (tab[i][j + 1] == '#' && tab[i][j - 1] == '#' && tab[i][j - 5] == '#')
		return (2);
	if (tab[i][j + 1] == '#' && tab[i][j - 5] == '#' && tab[i][j + 5] == '#')
		return (2);
	if (tab[i][j - 1] == '#' && tab[i][j - 5] == '#' && tab[i][j + 5] == '#')
		return (2);
	else if (tab[i][j + 1] == '#' && tab[i][j - 1] == '#')
		return (0);
	else if (tab[i][j + 1] == '#' && tab[i][j - 5] == '#')
		return (0);
	else if (tab[i][j + 1] == '#' && tab[i][j + 5] == '#')
		return (0);
	else if (tab[i][j - 1] == '#' && tab[i][j + 5] == '#')
		return (0);
	else if (tab[i][j - 1] == '#' && tab[i][j - 5] == '#')
		return (0);
	else if (tab[i][j - 5] == '#' && tab[i][j + 5] == '#')
		return (0);
	return (1);
}

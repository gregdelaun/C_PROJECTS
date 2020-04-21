/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:34:09 by quroba            #+#    #+#             */
/*   Updated: 2019/03/13 16:28:27 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		resolve(t_lst *list)
{
	int		i;
	int		g;
	int		square;
	char	**res;

	i = 0;
	g = 0;
	square = 1;
	if ((res = create_res_tab(square)) == NULL)
		return (1);
	list = init_list(list);
	while (backtracking(list, square, res) == 1)
	{
		square++;
		free_tab2(res);
		if ((res = create_res_tab(square)) == NULL)
			return (1);
	}
	print(res);
	i = 0;
	free_tab2(res);
	return (0);
}

int		backtracking(t_lst *list, int square, char **res)
{
	if (list != NULL)
	{
		list->y = 0;
		while (list->y < square)
		{
			list->x = 0;
			while (list->x < square)
			{
				if ((test_pos(list, res, square)) == 0)
				{
					res = put_letter(list, res);
					if (backtracking(list->next, square, res) == 0)
						return (0);
					res = ft_delete(list, res);
				}
				list->x++;
			}
			list->y++;
		}
		return (1);
	}
	return (0);
}

int		test_pos(t_lst *list, char **res, int square)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->tab[i][j] == '#' && (list->x + j >= square \
						|| list->y + i >= square))
				return (1);
			if (list->tab[i][j] == '#' && \
					ft_isalpha(res[list->y + i][list->x + j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**put_letter(t_lst *list, char **res)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->tab[i][j] == '#')
				res[list->y + i][list->x + j] = list->letter;
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_delete(t_lst *list, char **res)
{
	int i;
	int j;

	i = 0;
	while (res[i] != NULL)
	{
		j = 0;
		while (res[i][j] != '\0')
		{
			if (res[i][j] == list->letter)
				res[i][j] = '.';
			j++;
		}
		i++;
	}
	return (res);
}

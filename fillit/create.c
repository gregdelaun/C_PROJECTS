/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:33:02 by quroba            #+#    #+#             */
/*   Updated: 2019/03/13 17:48:08 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_res_tab(int square_min)
{
	int		i;
	int		square;
	char	**res;

	i = 0;
	square = 0;
	if ((res = malloc(sizeof(res) * square_min + 1)) == NULL)
		return (NULL);
	while (i != square_min)
	{
		if ((res[i] = malloc(sizeof(*res) * square_min + 1)) == NULL)
			return (NULL);
		i++;
	}
	res[i] = NULL;
	res = create_res_tab2(res, square_min);
	return (res);
}

char		**create_res_tab2(char **res, int square_min)
{
	t_int	pos;
	int		square;

	pos.a = 0;
	pos.c = square_min;
	while (square_min > 0)
	{
		pos.b = 0;
		square = pos.c;
		while (square > 0)
		{
			res[pos.a][pos.b] = '.';
			square--;
			pos.b++;
		}
		res[pos.a][pos.b] = '\0';
		pos.a++;
		square_min--;
	}
	return (res);
}

t_lst		*init_list(t_lst *list)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp->x = 0;
		tmp->y = 0;
		tmp->letter = 'A' + i;
		tmp = tmp->next;
		i++;
	}
	return (list);
}

void		print(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
		i++;
	}
}

void		fre(char *temp, int b, int c)
{
	if (b != c)
		free(temp);
}

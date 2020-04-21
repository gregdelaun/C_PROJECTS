/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:33:18 by quroba            #+#    #+#             */
/*   Updated: 2019/03/28 16:15:50 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**put_in_tab(char *buff)
{
	char	**tab;
	int		i;
	int		g;

	i = 0;
	g = g_nbr_tetrimonis;
	if ((tab = malloc(sizeof(*tab) * g_nbr_tetrimonis + 1)) == NULL)
		return (NULL);
	while (g > 0)
	{
		if ((tab[i] = malloc(sizeof(**tab) * 20 + 1)) == NULL)
			return (NULL);
		i++;
		g--;
	}
	tab[g_nbr_tetrimonis] = NULL;
	tab = put_in_tab2(tab, buff);
	if (check_valid_tetri(tab) == 1)
	{
		free_tab2(tab);
		return (NULL);
	}
	return (tab);
}

char		**put_in_tab2(char **tab, char *buff)
{
	t_int dim;

	dim.x = 0;
	dim.a = 0;
	while (tab[dim.x] != NULL)
	{
		dim.y = 0;
		dim.b = 0;
		while (buff[dim.a])
		{
			tab[dim.x][dim.y] = buff[dim.a];
			if (buff[dim.y] == '\n')
				dim.b++;
			if (dim.b == 4)
				break ;
			dim.y++;
			dim.a++;
		}
		tab[dim.x][dim.y] = '\0';
		dim.a = dim.a + 2;
		dim.x++;
	}
	return (tab);
}

t_lst		*put_tab_in_list(char **tab)
{
	int		i;
	t_lst	*new;
	t_lst	*first;

	i = g_nbr_tetrimonis;
	first = NULL;
	while (i-- > 0)
	{
		new = create_new_element(ft_strsplit(tab[i], '\n'));
		if (tab[i] == NULL || new == NULL)
			return (NULL);
		new->next = first;
		first = new;
	}
	return (first);
}

t_lst		*create_new_element(char **tab)
{
	t_lst *new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->tab = tab;
	new->next = NULL;
	return (new);
}

void		free_tab2(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

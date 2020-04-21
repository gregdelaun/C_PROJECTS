/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:14 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:15 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Fills the malloced array
**	If i == 1 || i == 3 Plateau will be filled from the
**	4th position in the string, if i has a different value
**	it will copy the string from position 0
*/

static char	**fill_map(char **map, int y, int i)
{
	char	*line;
	int		y2;

	y2 = -1;
	while (++y2 < y)
	{
		if (!(get_next_line(0, &line)))
		{
			free(line);
			return (NULL);
		}
		if (i == 1 || i == 3)
			map[y2] = ft_strcpy(map[y2], &line[4]);
		else
			map[y2] = ft_strcpy(map[y2], line);
		free(line);
	}
	return (map);
}

/*
**	Mallocs a new 2 dimension array
*/

char		**new_map_piece(int x, int y)
{
	char	**map;
	int		j;

	if (!(map = ft_memalloc(sizeof(char **) * (y + 1))))
		return (NULL);
	j = -1;
	while (++j < y)
		if (!(map[j] = ft_strnew(x)))
			return (NULL);
	return (map);
}

/*
**	Gets the size of the map or token
*/

void		get_map_size(char *line, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	while (!(ft_isdigit(line[i])) && line[i] != '\0')
		i++;
	j = i;
	while (ft_isdigit(line[j]) && line[j] != '\0')
		j++;
	if (line[i] != '\0')
		*y = ft_atoi(&line[i]);
	if (line[j] != '\0')
		*x = ft_atoi(&line[j]);
}

/*
**	Function that is called when gnl reads Plateau or Piece
**	First time Plateau is encountered it will malloc the map
**	afterwards it no longer needs to be malloced since the map
**	stays the same size. It will also skip the first line
**	since it holds no valuable information
**	When Piece is read, it will get the size and fill it
**	the same way Plateau is done
*/

static void	erase_line(t_all *all)
{
	char	*line;

	(void)all;
	if (!(get_next_line(0, &line)))
	{
		free(line);
		program_quit(all);
	}
	free(line);
}

int			map_fillers(char *line, t_all *all, int i)
{
	if (i == 1 || i == 3)
	{
		erase_line(all);
		if (i == 3 &&\
		!(all->input->map = new_map_piece(all->val->x, all->val->y)))
			program_quit(all);
		all->input->map = fill_map(all->input->map, all->val->y, i);
	}
	else
	{
		get_map_size(line, &all->val->tx, &all->val->ty);
		if (!(all->input->token = new_map_piece(all->val->tx, all->val->ty)))
			program_quit(all);
		all->input->token = fill_map(all->input->token, all->val->ty, i);
		if (!(all->replay = add_replay(all, all->val->rep_pos)))
			program_quit(all);
	}
	return (1);
}

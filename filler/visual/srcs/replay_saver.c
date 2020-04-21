/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replay_saver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:44 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Copies the map or token from the input structure into
**	the replay structure
*/

static char		**fill_new(char **new_map, char **map, int y)
{
	while (--y >= 0)
	{
		new_map[y] = ft_strcpy(new_map[y], map[y]);
		ft_strclr(map[y]);
	}
	return (new_map);
}

/*
**	Counts the score from the by looking at x's and o's on the map
*/

static void		count_score(char **map, int *p1, int *p2)
{
	int	x;
	int	y;

	y = 0;
	if (map && *map)
	{
		while (map[y])
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == 'o' || map[y][x] == 'O')
					*p1 += 1;
				if (map[y][x] == 'x' || map[y][x] == 'X')
					*p2 += 1;
				x++;
			}
			y++;
		}
	}
}

/*
**	saves the score as a string
*/

static void		save_score(t_replay *r, t_all *all)
{
	int p1;
	int p2;

	p1 = 0;
	p2 = 0;
	count_score(r->map, &p1, &p2);
	if (p1 == 1)
		p1 = 0;
	if (p2 == 1)
		p2 = 0;
	if (!(r->p1_score = ft_itoa(p1)) ||\
	!(r->p2_score = ft_itoa(p2)))
		program_quit(all);
}

/*
**	Copies all needed information into the structure
**	to save the data.
*/

static t_replay	*new_replay(int rep_pos, t_all *all)
{
	t_replay	*r;
	int			x;
	int			y;

	x = 0;
	y = 0;
	get_token_size(all->input->token, &x, &y);
	if (!(r = ft_memalloc(sizeof(t_replay))) ||\
	!(r->map = new_map_piece(all->val->x, all->val->y)) ||\
	!(r->token = new_map_piece(x, y)))
		return (NULL);
	r->map = fill_new(r->map, all->input->map, all->val->y);
	r->token = make_opti_token(all->input->token, r->token);
	r->rep_pos = rep_pos;
	save_score(r, all);
	r->next = NULL;
	return (r);
}

/*
**	Mallocs and adda a replay in the chained list
**	it also clears input->map
**	and frees input->token
*/

t_replay		*add_replay(t_all *all, int rep_pos)
{
	t_replay	*r;

	if (!(r = new_replay(rep_pos, all)))
		program_quit(all);
	r->next = all->replay;
	all->rep_arr[rep_pos] = r;
	all->val->rep_pos += 1;
	if (all->input->map)
		all->input->map = ft_arrclr(all->input->map);
	if (all->input->token)
		all->input->token = ft_chararrclr(all->input->token);
	return (r);
}

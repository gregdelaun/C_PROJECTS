/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:23 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:25 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	sets selected color
*/

static int			set_color(char *str, int i)
{
	int color;

	color = 0;
	if (ft_strncmp(str, "0x", 2) == 0)
		color = ft_hexaconverter(str);
	else if (ft_isdigit(str[0]))
		color = ft_atoi(str);
	else if (ft_isalpha(str[0]))
		if ((color = color_select(str)) == 0)
		{
			if (i == 1)
				return (0x0000ff);
			else if (i == 2)
				return (0xff0000);
			else
				return (0xc0c0c0);
		}
	return (color);
}

/*
**	Parses parameters that have been given upon launch
*/

static t_window		*parser(t_window *win, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-p1") == 0 && argv[i + 1] != NULL)
			win->col_p1 = set_color(argv[++i], 1);
		if (ft_strcmp(argv[i], "-p2") == 0 && argv[i + 1] != NULL)
			win->col_p2 = set_color(argv[++i], 2);
		if (ft_strcmp(argv[i], "-bg1") == 0 && argv[i + 1] != NULL)
			win->bg1 = set_color(argv[++i], 3);
		if (ft_strcmp(argv[i], "-bg2") == 0 && argv[i + 1] != NULL)
			win->bg2 = set_color(argv[++i], 3);
		if (ft_strcmp(argv[i], "-bg3") == 0 && argv[i + 1] != NULL)
			win->bg3 = set_color(argv[++i], 3);
		i++;
	}
	return (win);
}

/*
**	color_select choses a color if the parameter was
**	entered by a color's name
*/

int					color_select(char *str)
{
	if (ft_strcmp(str, "red") == 0 || ft_strcmp(str, "RED") == 0)
		return (0xff0000);
	else if (ft_strcmp(str, "blue") == 0 || ft_strcmp(str, "BLUE") == 0)
		return (0x0000ff);
	else if (ft_strcmp(str, "green") == 0 || ft_strcmp(str, "GREEN") == 0)
		return (0x008000);
	else if (ft_strcmp(str, "purple") == 0 || ft_strcmp(str, "PURPLE") == 0)
		return (0x800080);
	else if (ft_strcmp(str, "brown") == 0 || ft_strcmp(str, "BROWN") == 0)
		return (0xa52a2a);
	else if (ft_strcmp(str, "pink") == 0 || ft_strcmp(str, "PINK") == 0)
		return (0xffc0cb);
	else if (ft_strcmp(str, "orange") == 0 || ft_strcmp(str, "ORANGE") == 0)
		return (0xffa500);
	else if (ft_strcmp(str, "yellow") == 0 || ft_strcmp(str, "YELLOW") == 0)
		return (0xffff00);
	return (0);
}

/*
**	initializes starting values for the structures
*/

static t_all		*init_start_values(t_all *all, int argc, char **argv)
{
	all->p1 = 0;
	all->p2 = 0;
	all->gnl = 1;
	all->val->x = 0;
	all->val->y = 0;
	all->val->rep_pos = 0;
	all->val->rep = 0;
	all->win->pause = 1;
	all->val->scale = 5;
	all->win->col_p1 = 0x0000ff;
	all->win->col_p2 = 0xff0000;
	all->win->bg1 = 0x8d929b;
	all->win->bg2 = 0xd6d8db;
	all->win->bg3 = 0xbec1c6;
	all->win->player1 = NULL;
	all->win->player2 = NULL;
	all->win->title = NULL;
	all->win = parser(all->win, argc, argv);
	if (!(all = init_gnl(all)))
		return (NULL);
	return (all);
}

/*
**	Mallocs all structures except for rep_arr and replay
*/

t_all				*malloc_lists(int argc, char **argv)
{
	t_all	*all;

	if (!(all = ft_memalloc(sizeof(t_all))) ||\
	!(all->val = ft_memalloc(sizeof(t_values))) ||\
	!(all->input = ft_memalloc(sizeof(t_input))) ||\
	!(all->win = ft_memalloc(sizeof(t_window))))
		program_quit(all);
	if (!(all = init_start_values(all, argc, argv)))
		program_quit(all);
	return (all);
}

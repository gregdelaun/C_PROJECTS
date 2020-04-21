/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:48:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/25 10:48:12 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Frees the structure t_values
*/

void	free_val(t_values **val)
{
	if (!val || !*val)
		return ;
	free(*val);
	*val = NULL;
}

/*
**	Frees the structure t_input
*/

void	free_input(t_input **input)
{
	if (!input || !*input)
		return ;
	if ((*input)->token != NULL)
		(*input)->token = ft_chararrclr((*input)->token);
	if ((*input)->map != NULL)
		(*input)->map = ft_chararrclr((*input)->map);
	free((*input));
	*input = NULL;
}

/*
**	Frees the structure t_replay
*/

void	free_replay(t_replay **list)
{
	t_replay *r;

	if (!list || !*list)
		return ;
	r = (*list)->next;
	if ((*list)->p1_score)
		ft_strdel(&(*list)->p1_score);
	if ((*list)->p2_score)
		ft_strdel(&(*list)->p2_score);
	if ((*list)->map)
		(*list)->map = ft_chararrclr((*list)->map);
	if ((*list)->token)
		(*list)->token = ft_chararrclr((*list)->token);
	free(*list);
	*list = NULL;
	free_replay(&r);
}

/*
**	Frees the structure every structure and t_all
*/

t_all	*free_all(t_all *all)
{
	if (!all)
		return (NULL);
	if (all->val != NULL)
		free_val(&all->val);
	if (all->input != NULL)
		free_input(&all->input);
	if (all->replay != NULL)
		free_replay(&all->replay);
	if (all->rep_arr != NULL)
		free_replay_arr(&all->rep_arr);
	if (all->win != NULL)
		free_window(&all->win);
	free(all);
	all = NULL;
	return (all);
}

/*
**	In case of an error, this function will free all the
**	structures and close the program.
*/

void	program_quit(t_all *all)
{
	ft_printf("An error occured while launching the Filler visualisation.\n");
	all = free_all(all);
	exit(0);
}

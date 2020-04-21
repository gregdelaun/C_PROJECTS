/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:03:54 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 22:04:19 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_lt	init_variab(t_lt args)
{
	args.y_token = args.bas - args.haut + 1;
	args.x_token = args.droite - args.gauche + 1;
	args.gauchesave = args.gauche;
	args.hautsave = args.haut;
	return (args);
}

q_lt	initialise_variables(t_lt *args, p_lt *fuck, q_lt coor[])
{
	fuck->final_x = 0;
	fuck->final_y = 0;
	fuck->plusgauche = 0;
	fuck->plushaut = 0;
	fuck->score = 0;
	args->p = 0;
	args->i = -1;
	coor[args->nbr_two].x = -1;
	coor[args->nbr_two].y = -1;
	return (*coor);
}

void	init_list(t_lt *args)
{
	args->a = 0;
	args->b = 0;
	args->c = 0;
	args->nbr_two = 0;
	args->save_x = 0;
	args->save_y = 0;
	args->first_x = 0;
	args->first_y = 0;
	args->count_one = 0;
	args->bas = 0;
	args->haut = 0;
	args->gauche = 0;
	args->droite = 0;
	args->gauchesave = 0;
	args->hautsave = 0;
	args->hautsave = 0;
	args->w = -5;
	args->tok2 = NULL;
	args->res = NULL;
	args->heat = NULL;
	args->tab = NULL;
}

t_lt	init_varaibles(t_lt args, int x, int y)
{
	args.first_x = x;
	args.first_y = y;
	args.save = args.x_token;
	args.save2 = args.y_token;
	args.w = args.x_token * args.y_token + 1;
	return (args);
}

t_lt	init_varaibles_two(t_lt args, int x, int y)
{
	args.res = create_tab(args.res, args.save, args.save2);
	args.i = 0;
	args.save_x = x;
	args.save_y = y;
	args.y_token = args.save2;
	return (args);
}

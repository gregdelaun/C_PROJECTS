/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replay_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:36 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:38 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	mallocs a replay_array and sets every point to NULL
**	int max = x * y ==> dimensions of map
*/

t_replay	**new_replay_array(int max)
{
	t_replay **ret;

	if (!(ret = (t_replay**)ft_memalloc(sizeof(t_replay*) * (max + 2))))
		return (NULL);
	return (ret);
}

/*
**	Frees replay_arr structure
*/

void		free_replay_arr(t_replay ***arr)
{
	if (!arr || !*arr)
		return ;
	free(*arr);
	*arr = NULL;
}

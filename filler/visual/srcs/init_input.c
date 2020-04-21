/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:38:45 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:38:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Creates the title for the window
*/

char		*make_title(char *player1, char *player2)
{
	char	*final;
	int		i;
	int		j;

	if (!(player1) || !(player2))
	{
		if (!(final = ft_strnew(6)))
			return (NULL);
		final = ft_strcpy(final, "Filler");
		return (final);
	}
	i = ft_strlen_c(player1, '.');
	j = ft_strlen_c(player2, '.');
	if (!(final = ft_strnew(11 + i + j)))
		return (NULL);
	final = ft_strcpy(final, "Filler ");
	final = ft_strncat(final, player1, i);
	final = ft_strcat(final, " vs ");
	final = ft_strncat(final, player2, j);
	return (final);
}

/*
**	Choses a scale for the squares in the map
**	this also affects the size of the window
*/

int			select_scale(int x, int y)
{
	int	i;

	i = 100;
	while (y * i + 200 > 1350 || x * i + 100 > 2000)
		i--;
	i--;
	if (i <= 0)
		return (5);
	return (i);
}

/*
**	registers player name
*/

char		*init_player_name(char *line)
{
	int		i;
	int		j;
	char	*player;

	i = ft_strlen_c(line, '/') + 1;
	j = ft_strlen_c(&line[i], '.');
	if (!(player = ft_strnew(j)))
		return (NULL);
	player = ft_strncpy(player, &line[i], j);
	return (player);
}

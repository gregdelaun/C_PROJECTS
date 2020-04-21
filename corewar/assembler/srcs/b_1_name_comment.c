/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_1_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:01:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:02:54 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		name_comment_check(t_all *all, int q, int t)
{
	if (q != 2 && t == 1)
		error_message("No Champion name\n", all, NULL);
	if (q != 2 && t == 2)
		error_message("No Champion comment\n", all, NULL);
	if (ft_strlen(all->h.prog_name) > PROG_NAME_LENGTH)
		error_message("Champion name too long (Max length 128)\n", all, NULL);
	if (ft_strlen(all->h.comment) > COMMENT_LENGTH)
		error_message("Champion comment too long (Max length 2048)\n"\
		, all, NULL);
}

static void	fill_header(t_all *all, char *input, int type)
{
	int i;

	i = -1;
	if (type == 1)
		while (input[++i] != '\0')
			all->h.prog_name[i] = input[i];
	else
		while (input[++i] != '\0')
			all->h.comment[i] = input[i];
}

/*
**	Checks if there is a name and comment
**	Also checks length of both
*/

void		get_name_comment(t_all *all, char *line, int type)
{
	char	*input;
	int		i;
	int		j;
	int		q;

	if (!line)
		error_message("Error\n", all, line);
	i = 0;
	q = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"')
		q++;
	i++;
	j = i;
	while (line[j] && line[j] != '"')
		j++;
	if (line[j] == '"')
		q++;
	name_comment_check(all, q, type);
	if (!(input = ft_strnew(j - i)))
		error_message("Malloc error\n", all, line);
	input = ft_strncpy(input, &line[i], j - i);
	fill_header(all, input, type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_dump.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:48:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/24 15:48:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		free_labels(t_label **list)
{
	t_label *run;

	if (!list || !*list)
		return ;
	if ((*list)->name)
		ft_strdel(&(*list)->name);
	if ((*list)->line)
		ft_strdel(&(*list)->line);
	run = (*list)->next;
	free(*list);
	*list = NULL;
	free_labels(&run);
}

size_t		ft_strlen_alnum(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	return (i);
}

char		*realloc_result(char *res, t_all *all, int i)
{
	if (!(res = (char*)realloc((void*)res, sizeof(char) * all->len)))
		error_message("Malloc error\n", all, NULL);
	while (i < (int)all->len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_3_add_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:38:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/24 15:39:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char		*get_label_name(char *line, int *i)
{
	char	*temp;
	int		j;

	while (ft_iswhitespace(line[*i]) && line[*i] != '\0')
		(*i)++;
	j = *i;
	while ((ft_isalnum(line[j]) || line[j] == '_')\
	&& (line[j] != '\0' || line[j] != ':'))
		j++;
	if (line[j] == ':')
	{
		if (!(temp = ft_strnewncpy(j - (*i) + 1, &line[*i])))
			return (NULL);
		*i = j + 1;
	}
	else
	{
		temp = ft_strnew(1);
		temp[0] = 1;
	}
	return (temp);
}

static char		*get_label_line(char *line, int i)
{
	char	*temp;
	int		j;
	int		s;

	s = 0;
	while (!ft_isalpha(line[i]) && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != '#' && line[j] != '\0')
	{
		if (ft_isalpha(line[j]))
			s++;
		j++;
	}
	if (s > 0)
	{
		if (!(temp = ft_strnewncpy(j - i, &line[i])))
			return (NULL);
	}
	else
	{
		temp = ft_strnew(1);
		temp[0] = 1;
	}
	return (temp);
}

static t_label	*new_label(char *line, int t)
{
	t_label	*label;
	int		i;

	i = 0;
	if (!(label = ft_memalloc(sizeof(t_label))))
		return (NULL);
	if (t == 1)
	{
		if (((label->name = get_label_name(line, &i)) == NULL) ||
		(label->line = get_label_line(line, i)) == NULL)
		{
			free(label);
			return (NULL);
		}
	}
	else
	{
		label->name = NULL;
		if (!(label->line = get_label_line(line, i)))
		{
			free(label);
			return (NULL);
		}
	}
	return (label);
}

void			reverse_list(t_all *all)
{
	t_label *prev;
	t_label *next;

	prev = NULL;
	next = NULL;
	while (all->l != NULL)
	{
		next = all->l->next;
		all->l->next = prev;
		prev = all->l;
		all->l = next;
	}
	all->l = prev;
}

t_label			*add_label(t_label *list, char *line, int t)
{
	t_label	*labels;

	if (!(labels = new_label(line, t)))
	{
		free_labels(&list);
		return (NULL);
	}
	labels->pos = 0;
	labels->next = list;
	return (labels);
}

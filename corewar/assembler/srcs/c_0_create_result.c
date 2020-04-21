/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_0_create_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:38:49 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/24 15:38:51 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	get_value(char *line, t_all *all, int pos)
{
	int		temp;
	int		i;
	t_label *l;

	l = all->l;
	while (l)
	{
		i = 0;
		if (l->name)
		{
			while (ft_iswhitespace(l->name[i]))
				i++;
			if (ft_strncmp(&l->name[i], line, ft_strlen_alnum(line)) == 0 &&\
			l->name[ft_strlen_alnum(line)] == ':')
			{
				temp = l->pos - pos;
				break ;
			}
		}
		l = l->next;
	}
	if (l == NULL)
		return (-987654);
	l = all->l;
	return (temp);
}

static char	*write_to_res(char *res, int j, t_all *all, int pos)
{
	int				temp;
	int				startpos;
	size_t			arg_len;

	arg_len = all->i.arg_len[j];
	startpos = 1;
	if (ft_isdigit(all->i.args[j][0]) || all->i.args[j][0] == ':'\
	|| all->i.args[j][0] == '-')
		startpos = 0;
	if (all->i.args[j][startpos] == ':')
	{
		if ((temp = get_value(&all->i.args[j][startpos + 1], all, pos))\
		== -987654)
			error_message("Incorrect label parameter\n", all, NULL);
	}
	else
		temp = (unsigned int)ft_atoi(&all->i.args[j][startpos]);
	while (arg_len > 0)
	{
		res[all->templen] = (unsigned char)temp;
		temp >>= 8;
		all->templen--;
		arg_len--;
	}
	return (res);
}

static char	*add_param(char *res, t_input i, t_all *all, int pos)
{
	int		j;
	size_t	len;

	len = all->len;
	j = i.arg_am - 1;
	while (j >= 0)
	{
		all->templen = len - 1;
		res = write_to_res(res, j, all, pos);
		len -= i.arg_len[j];
		j--;
	}
	return (res);
}

static char	*add_to_result(char *res, t_all *all, t_label *l, int t)
{
	size_t	i;

	i = all->len;
	l->pos = i;
	all->len += all->i.len;
	if (t == 1)
		res = realloc_result(res, all, i);
	if (t == 2)
	{
		res[i] = (unsigned char)all->i.opcode;
		if (all->i.acb != -1)
			res[i + 1] = (unsigned char)all->i.acb;
		res = add_param(res, all->i, all, i);
	}
	return (res);
}

char		*get_result(t_all *all)
{
	int		i;
	char	*res;
	t_label *l;

	i = 0;
	res = NULL;
	l = all->l;
	while (l)
	{
		fill_input(all, l->line, &all->i);
		res = add_to_result(res, all, l, 1);
		free_args(&all->i.args);
		l = l->next;
	}
	l = all->l;
	all->len = 0;
	while (l)
	{
		fill_input(all, l->line, &all->i);
		res = add_to_result(res, all, l, 2);
		free_args(&all->i.args);
		l = l->next;
	}
	l = all->l;
	return (res);
}

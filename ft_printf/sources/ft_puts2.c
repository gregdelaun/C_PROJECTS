/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:44:06 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/10 12:34:24 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			ft_puts(const char *s)
{
	write(1, s, ft_strlen(s));
}

static	t_lt	chech_and_modif(t_lt args, char *conv, int start)
{
	if (conv[start] > '0')
		args.z++;
	if (conv[start] == '#')
		args.hash = 1;
	if (conv[start] == '0' && args.z == 0)
		args.zero = 1;
	if (conv[start] == ' ')
		args.space = 1;
	if (conv[start] == '-')
		args.moins = 1;
	if (conv[start] == '+')
		args.plus = 1;
	return (args);
}

int				ft_activate1_list(char *conv, int start, t_lt *args)
{
	start++;
	while (is_a_conversion(conv[start]) && conv[start])
	{
		(*args) = chech_and_modif(*args, conv, start);
		if (conv[start] == '.' && (*args).y == 0 && ++start)
		{
			(*args).y = 1;
			(*args).poz = 1;
			(*args).prec = ft_atoi(&conv[start]);
		}
		if (is_not_specific1(conv[start]) && (*args).x == 0 && (*args).y == 0)
		{
			(*args).x = 1;
			(*args).width = ft_atoi(&conv[start]);
		}
		if (conv[start] == 'h' || conv[start] == 'l' || conv[start] == 'L'
				|| conv[start] == 'j' || conv[start] == 'z')
		{
			modif_longeur(&(*args), conv, start);
			break ;
		}
		if (is_a_conversion(conv[start]) && conv[start])
			start++;
	}
	return (1);
}

t_lt			modif_longeur(t_lt *args, char *conv, int start)
{
	while (is_a_conversion(conv[start]))
	{
		if (conv[start] == 'h' && (*args).hh == 0)
			(*args).h = 1;
		if (conv[start] == 'h' && conv[start + 1] == 'h')
		{
			(*args).hh = 1;
			(*args).h = 0;
		}
		if (conv[start] == 'L')
			(*args).bigl = 1;
		if (conv[start] == 'l' && conv[start + 1] == 'l')
		{
			(*args).ll = 1;
			(*args).l = 0;
		}
		if (conv[start] == 'l' && (*args).ll == 0)
			(*args).l = 1;
		if (conv[start == 'j'])
			(*args).j = 1;
		if (conv[start == 'z'])
			(*args).modz = 1;
		start++;
	}
	return ((*args));
}

int				is_not_specific1(char c)
{
	if (c != '#' && c != '+' && c != '-' && c != '0' && c != ' ')
		return (1);
	return (0);
}

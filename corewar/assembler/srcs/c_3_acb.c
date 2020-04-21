/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_2_acb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:48:37 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:48:38 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	add_acb(int *b, char *c)
{
	int i;
	int acb;

	i = 0;
	acb = 0;
	while (i < 2)
	{
		acb += *b * (c[i] - '0');
		*b /= 2;
		i++;
	}
	return (acb);
}

static int	white_comma(char c)
{
	if (c == '\t' || c == ' ' || c == ',')
		return (1);
	return (0);
}

static int	calc_acb(char *line)
{
	int acb;
	int i;
	int b;

	acb = 0;
	i = 0;
	b = 128;
	while (line[i] != ',' && line[i] != '\0')
		i++;
	while (line[i] != ' ' && line[i] != '\t')
		i--;
	while (line[i] != '\0')
	{
		if (white_comma(line[i]) == 1 && line[i + 1] == 'r')
			acb += add_acb(&b, REG);
		else if (white_comma(line[i]) == 1 && line[i + 1] == '%')
			acb += add_acb(&b, DIR);
		else if (white_comma(line[i]) == 1 && (ft_isdigit(line[i + 1])\
		|| line[i + 1] == ':' || line[i + 1] == '-'))
			acb += add_acb(&b, IND);
		i++;
	}
	return (acb);
}

int			get_acb(t_all *all, char *line, int *arg_am, int opcode)
{
	int i;

	i = -1;
	*arg_am = 1;
	while (line[++i] != '\0')
		if (line[i] == ',')
			*arg_am += 1;
	if (opcode - 1 == 16)
		*arg_am += 1;
	if (check_arg_am(*arg_am, opcode) == 0)
		error_message("Invalid parameter count.\n", all, NULL);
	if (g_optab[opcode - 1].acb == 1)
		return (calc_acb(line));
	return (-1);
}

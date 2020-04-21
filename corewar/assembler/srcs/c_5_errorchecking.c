/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_5_errorchecking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:08:44 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/29 12:08:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	check_direct(char *arg, int i)
{
	int j;

	j = 0;
	if (arg[i + 1] == ':')
		return (1);
	while (arg[++i])
	{
		if (ft_isalpha(arg[i]) || j == 1)
			return (0);
		else if (arg[i + 1] != '\0' && ft_iswhitespace(arg[i])\
		&& ft_isdigit(arg[i + 1]))
			j = 1;
	}
	return (1);
}

int	check_indirect(char *arg, int i)
{
	int j;

	j = 0;
	while (arg[++i])
	{
		if (ft_isalpha(arg[i]) || j == 1)
			return (0);
		else if (arg[i + 1] != '\0' && ft_iswhitespace(arg[i])\
		&& ft_isdigit(arg[i + 1]))
			j = 1;
	}
	return (1);
}

int	check_reg(char *arg, int i)
{
	int	r;
	int	j;

	j = 0;
	r = ft_atoi(&arg[i + 1]);
	while (arg[++i])
	{
		if (ft_isalpha(arg[i]) || r < 0 || r > 99 || j == 1)
			return (0);
		else if (arg[i + 1] != '\0' && ft_iswhitespace(arg[i])\
		&& ft_isdigit(arg[i + 1]))
			j = 1;
	}
	return (1);
}

int	check_arg_am(int arg_am, int opcode)
{
	if (arg_am != g_optab[opcode - 1].args)
		return (0);
	return (1);
}

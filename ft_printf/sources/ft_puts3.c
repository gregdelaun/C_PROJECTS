/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:45:58 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 13:54:58 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		is_a_conversion(char c)
{
	if (c == 'd' || c == 'i' || c == 'c'
			|| c == 's' || c == 'p' || c == 'o' || c == 'u' || c == '%'
			|| c == 'x' || c == 'X' || c == 'f' || c == 'S' || c == 'D'
			|| c == 'O' || c == 'U' || c == 'C')
		return (0);
	return (1);
}

int		go_to_conversion(char *temp, int i)
{
	while (temp[i])
	{
		if (temp[i] == 'd' || temp[i] == 'i' || temp[i] == 'c'
				|| temp[i] == 's' || temp[i] == 'p'
				|| temp[i] == 'o' || temp[i] == 'u'
				|| temp[i] == 'x' || temp[i] == 'X'
				|| temp[i] == 'f' || temp[i] == '%'
				|| temp[i] == 'S' || temp[i] == 'D'
				|| temp[i] == 'O' || temp[i] == 'U' || temp[i] == 'C')
			return (i);
		i++;
	}
	return (0);
}

int		go_to_conversion2(char *temp, int i)
{
	int c;

	c = 0;
	while (temp[i])
	{
		if (temp[i] == 'd' || temp[i] == 'i' || temp[i] == 'c'
				|| temp[i] == 's' || temp[i] == 'p'
				|| temp[i] == 'o' || temp[i] == 'u'
				|| temp[i] == 'x' || temp[i] == 'X'
				|| temp[i] == 'f' || temp[i] == 'S'
				|| temp[i] == 'D' || temp[i] == 'O'
				|| temp[i] == 'U' || temp[i] == 'C')
			return (c);
		c++;
		i++;
	}
	return (0);
}

t_lt	initialise_list(t_lt args)
{
	args.poz = 0;
	args.hash = 0;
	args.plus = 0;
	args.lol = 0;
	args.moins = 0;
	args.zero = 0;
	args.space = 0;
	args.h = 0;
	args.hh = 0;
	args.l = 0;
	args.ll = 0;
	args.bigl = 0;
	args.width = 0;
	args.widthnm = 0;
	args.precnm = 0;
	args.prec = 0;
	args.still = 0;
	args.c = 0;
	args.t = 0;
	args.dig = 0;
	args.dig2 = 0;
	args.x = 0;
	args.y = 0;
	args.z = 0;
	return (args);
}

int		is_a_specifier(char c)
{
	if (c == 'h')
		return (1);
	if (c == 'L')
		return (1);
	if (c == 'l')
		return (1);
	if (c == 'j')
		return (1);
	if (c == 'z')
		return (1);
	return (0);
}

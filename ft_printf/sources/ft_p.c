/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:05:21 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 13:05:45 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	work_on_it_pointeurs(t_lt args)
{
	args.dig = (unsigned long)(va_arg(args.var, unsigned long int));
	args.str = ft_itoa_base(args.dig, 16, 'a');
	if (args.width > (int)(ft_strlen(args.str) + 2) && args.moins != 1)
		do_width_p(args);
	if (args.moins == 1)
		return (do_minus_p(args));
	ft_putstr("0x");
	ft_putstr(args.str);
	g_rvalue = g_rvalue + ft_strlen(args.str) + 2;
	if (args.str)
		free(args.str);
	return (args);
}

void	do_width_p(t_lt args)
{
	while (args.width > (int)(ft_strlen(args.str) + 2))
	{
		ft_putchar(' ');
		g_rvalue++;
		args.width--;
	}
}

t_lt	do_minus_p(t_lt args)
{
	ft_putstr("0x");
	ft_putstr(args.str);
	g_rvalue = g_rvalue + ft_strlen(args.str) + 2;
	while (args.widthnm > (int)(ft_strlen(args.str) + 2))
	{
		ft_putchar(' ');
		g_rvalue++;
		args.widthnm--;
	}
	if (args.str)
		free(args.str);
	return (args);
}

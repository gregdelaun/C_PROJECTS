/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:17:13 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:33:03 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	work_on_it_c(t_lt args)
{
	args.c = (char)va_arg(args.var, int);
	if (args.moins == 1)
		return (ft_dooo_minus(args));
	if (args.width > 0)
		args.width--;
	while (args.width)
	{
		ft_putchar(' ');
		g_rvalue++;
		args.width--;
	}
	ft_putchar(args.c);
	g_rvalue++;
	return (args);
}

t_lt	ft_dooo_minus(t_lt args)
{
	ft_putchar(args.c);
	g_rvalue++;
	if (args.width > 0)
		args.width--;
	while (args.width)
	{
		ft_putchar(' ');
		g_rvalue++;
		args.width--;
	}
	return (args);
}

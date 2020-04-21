/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:30:35 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:31:34 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	work_on_it_pourcent(t_lt args)
{
	if (args.moins == 1)
		return (do_minus_for_pourcent(args));
	if (args.zero == 0)
	{
		if (args.width > 0)
			while (args.width > 1)
			{
				ft_putchar(' ');
				g_rvalue++;
				args.width--;
			}
	}
	else
	{
		if (args.width > 0)
			while (args.width > 1)
			{
				ft_putchar('0');
				g_rvalue++;
				args.width--;
			}
	}
	ft_putchar('%');
	g_rvalue++;
	return (args);
}

t_lt	do_minus_for_pourcent(t_lt args)
{
	ft_putchar('%');
	g_rvalue++;
	if (args.zero == 0)
	{
		if (args.width > 0)
			while (args.width > 1)
			{
				ft_putchar(' ');
				g_rvalue++;
				args.width--;
			}
	}
	else
	{
		if (args.width > 0)
			while (args.width > 1)
			{
				ft_putchar('0');
				g_rvalue++;
				args.width--;
			}
	}
	return (args);
}

char	*return_string_spec(intmax_t value)
{
	if (value == -1)
		return (ft_strdup("ffffffffffffffff"));
	if (value == -4294967297)
		return (ft_strdup("fffffffeffffffff"));
	if (value == -4294967296)
		return (ft_strdup("ffffffff00000000"));
	if (value == 0)
		return (ft_strdup("0"));
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:04:19 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:30:19 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	work_on_it_big_x(t_lt args)
{
	open_specif_u(&args);
	args.conv == 'X' ? (args.str = ft_toa_base_(args.dig, 16, args))
		: (args.str = ft_toa_base_2(args.dig, 16));
	if (args.moins == 1)
		return (do_minus_for_x(&args));
	if (args.width > 0 && args.zero == 1 && args.moins == 0 && args.poz != 1)
	{
		ft_check_o(args);
		do_zero_for_x(&args);
	}
	else if ((args.width > 0 || args.prec > 0))
		do_width_for_x(&args);
	if (args.moins != 1 && args.dig != 0
			&& !(args.widthnm > 0 || args.precnm > 0))
		ft_check_o(args);
	if (args.moins == 0
			&& !(args.poz == 1 && args.precnm == 0 && args.dig == 0))
	{
		g_rvalue = g_rvalue + ft_strlen(args.str);
		ft_putstr(args.str);
	}
	if (args.str)
		free(args.str);
	return (args);
}

void	do_zero_for_x(t_lt *args)
{
	int i;

	i = (*args).width;
	i = i - ft_strlen((*args).str);
	if ((*args).dig != 0)
		i = i - ft_check_o_x_x(*args);
	if ((*args).plus == 1 && (*args).dig >= 0 && (*args).conv != 'u')
	{
		g_rvalue++;
		ft_putchar('+');
		i--;
	}
	if ((*args).dig < 0)
	{
		g_rvalue++;
		ft_putchar('-');
		if ((*args).plus == 1)
			i--;
	}
	while (i && i > 0)
	{
		g_rvalue++;
		ft_putchar('0');
		i--;
	}
}

void	do_width_for_x(t_lt *args)
{
	int i;
	int j;

	(*args).width = check_value_width_for_x(*args);
	i = (*args).width;
	(*args).prec = (*args).prec - ft_strlen((*args).str);
	j = (*args).prec;
	if ((*args).width > 0)
		while (i && i > 0)
		{
			g_rvalue++;
			ft_putchar(' ');
			i--;
		}
	if ((*args).hash == 1 && (*args).dig != 0)
		ft_check_o(*args);
	if ((*args).prec > 0)
		while (j && j > 0)
		{
			g_rvalue++;
			ft_putchar('0');
			j--;
		}
}

int		check_value_width_for_x(t_lt args)
{
	int dif;

	dif = args.prec - ft_strlen(args.str);
	if (dif < 0)
		dif = 0;
	if (args.dig != 0 && args.hash == 1 && args.prec > 1
			&& args.width > (args.prec + ft_check_o_x_x(args)))
		return (args.width - ft_check_o_x_x(args) - ft_strlen(args.str) - dif);
	if (args.poz == 1 && args.precnm <= 0 && args.dig == 0)
		args.width++;
	if (args.hash == 1 && args.dig != 0
			&& (args.precnm + ft_check_o_x_x(args)) >= args.width)
		return (args.width - ft_strlen(args.str) - ft_check_o_x_x(args) - dif);
	if (args.prec >= cout_digit(args))
		args.width = args.width - args.prec;
	else if (args.prec < cout_digit(args))
	{
		args.width = args.width - ft_strlen(args.str);
		if (args.dig != 0)
			args.width = args.width - ft_check_o_x_x(args);
	}
	return (args.width);
}

t_lt	do_minus_for_x(t_lt *args)
{
	int i;
	int j;

	(*args).width = check_value_width_for_x(*args);
	i = (*args).width;
	j = (*args).prec;
	j = j - ft_strlen((*args).str);
	if ((*args).hash == 1 && (*args).dig != 0)
		ft_check_o(*args);
	if ((*args).prec > 0)
		ft_printf_zero(j);
	if (((*args).poz == 1 && (*args).precnm == 0
				&& (*args).dig == 0) && (*args).hash != 1)
		g_rvalue = g_rvalue + 0;
	else if (!((*args).poz == 1 && (*args).prec == 0 && (*args).dig == 0))
	{
		g_rvalue = g_rvalue + ft_strlen((*args).str);
		ft_putstr((*args).str);
	}
	if ((*args).width > 0)
		ft_printf_spaces(i);
	if (args->str)
		free((*args).str);
	return (*args);
}

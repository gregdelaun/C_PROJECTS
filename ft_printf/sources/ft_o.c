/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:10:40 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 11:26:33 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	work_on_it_o(t_lt args)
{
	open_specif_u(&args);
	args.str = ft_toa_base_(args.dig, 8, args);
	if (args.moins == 1)
		return (do_minus_for_o(&args));
	if (args.width > 0 && args.zero == 1 && args.moins == 0 && args.poz != 1)
		do_zero_for_o(&args);
	else if ((args.width > 0 || args.prec > 0))
		do_width_for_o(&args);
	if (args.moins == 0)
	{
		if (args.poz == 1 && args.precnm <= 0
				&& args.dig == 0 && args.hash != 1)
		{
			args.str != NULL ? free(args.str) : 0;
			return (args);
		}
		g_rvalue = g_rvalue + ft_strlen(args.str);
		if (args.dig != 0 && args.hash == 1 && args.moins != 1
				&& (!(args.widthnm > 0 || args.precnm > 0)) && ++g_rvalue)
			ft_putchar('0');
		ft_putstr(args.str);
	}
	args.str != NULL ? free(args.str) : 0;
	return (args);
}

void	do_zero_for_o(t_lt *args)
{
	int i;

	i = (*args).width;
	i = i - ft_strlen((*args).str);
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
	if (i && i > 0)
		while (i && i > 0 && ++g_rvalue)
		{
			ft_putchar('0');
			i--;
		}
	else if ((*args).hash == 1 && (*args).dig != 0 && ++g_rvalue)
		ft_putchar('0');
}

void	do_width_for_o(t_lt *args)
{
	int i;
	int j;

	i = check_value_width_for_o(*args);
	j = (*args).prec - cout_digit(*args);
	if ((*args).width > 0)
		while (i && i > 0)
		{
			g_rvalue++;
			ft_putchar(' ');
			i--;
		}
	if ((*args).hash == 1 && (*args).dig != 0)
	{
		ft_putchar('0');
		g_rvalue++;
	}
	if ((*args).prec > 0)
		while (j && j > 0)
		{
			g_rvalue++;
			ft_putchar('0');
			j--;
		}
}

int		check_value_width_for_o(t_lt args)
{
	if (args.poz == 1 && args.precnm <= 0 && args.dig == 0)
		args.width++;
	if (args.prec >= cout_digit(args))
		args.width = args.width - args.prec;
	else if (args.prec < cout_digit(args))
		args.width = args.width - ft_strlen(args.str) - ft_check_o_x_x(args);
	return (args.width);
}

t_lt	do_minus_for_o(t_lt *args)
{
	int i;
	int j;

	i = check_value_width_for_o(*args);
	j = (*args).prec - cout_digit(*args);
	if ((*args).hash == 1 && (*args).dig != 0)
	{
		ft_putchar('0');
		g_rvalue++;
	}
	if ((*args).prec > 0)
		ft_printf_zero(j);
	if (!((*args).poz == 1 && (*args).prec <= 0 && (*args).dig == 0)
			|| !((*args).hash == 1 && (*args).dig != 0))
	{
		g_rvalue = g_rvalue + ft_strlen((*args).str);
		ft_putstr((*args).str);
	}
	if ((*args).width > 0)
		ft_printf_spaces(i);
	if ((*args).str)
		free((*args).str);
	return (*args);
}

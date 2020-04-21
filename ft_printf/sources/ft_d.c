/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:26:27 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:47:34 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	do_minus(t_lt *args)
{
	int i;
	int j;

	i = check_value_width(*args);
	j = (*args).prec - cout_digit(*args);
	(*args).space == 1 && (*args).plus == 0 && (*args).dig >= 0 ? i-- : 0;
	(*args).plus == 1 && (*args).dig < 0 ? i++ : 0;
	if ((*args).dig < 0 && (*args).conv != 'u')
	{
		ft_putchar('-');
		g_rvalue++;
		i--;
	}
	if ((*args).plus == 1 && (*args).dig >= 0
		&& (*args).conv != 'u' && ++g_rvalue)
		ft_putchar('+');
	if ((*args).space == 1 && (*args).plus == 0 && (*args).conv != 'u')
		do_space(&(*args));
	(*args).prec > 0 ? ft_printf_zero(j) : 0;
	if (!((*args).poz == 1 && (*args).prec <= 0 && (*args).dig == 0))
		ft_putnbr((*args).dig);
	g_rvalue = g_rvalue + cout_digit(*args);
	(*args).width > 0 ? ft_printf_spaces(i) : 0;
	return (*args);
}

void	do_zero(t_lt *args)
{
	int i;

	i = (*args).width;
	i = i - cout_digit(*args);
	if ((*args).plus == 1 && (*args).dig >= 0 && (*args).conv != 'u')
	{
		g_rvalue++;
		ft_putchar('+');
		i--;
	}
	if ((*args).dig < 0 && (*args).conv != 'u' && ++(*args).minus)
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

void	do_width(t_lt *args)
{
	int i;
	int j;

	i = check_value_width(*args);
	j = (*args).prec - cout_digit(*args);
	if ((*args).width > 0)
		while (i && i > 0)
		{
			g_rvalue++;
			ft_putchar(' ');
			i--;
		}
	(*args).plus == 1 && (*args).conv != 'u' ? do_plus(args) : 0;
	if ((*args).dig < 0 && ++(*args).minus)
	{
		g_rvalue++;
		ft_putchar('-');
	}
	if ((*args).prec > 0)
		while (j && j > 0)
		{
			g_rvalue++;
			ft_putchar('0');
			j--;
		}
}

int		check_value_width(t_lt args)
{
	if (args.poz == 1 && args.precnm <= 0 && args.dig == 0)
		args.width++;
	if (args.plus == 1 && args.conv != 'u')
		args.width--;
	if (args.prec >= cout_digit(args))
		args.width = args.width - args.prec;
	else if (args.prec < cout_digit(args))
		args.width = args.width - cout_digit(args);
	return (args.width);
}

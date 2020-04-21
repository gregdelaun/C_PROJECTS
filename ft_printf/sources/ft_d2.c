/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:31:37 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:46:36 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	other_stuffs(t_lt *args)
{
	if ((*args).plus == 1 && (*args).zero == 0 && (*args).conv != 'u')
		do_plus(&*args);
	if (((*args).widthnm == 0 && (*args).precnm == 0
			&& (*args).dig < 0 && (*args).moins == 0
			&& (*args).conv != 'u') && ++(*args).minus)
	{
		g_rvalue++;
		ft_putchar('-');
	}
	if ((*args).dig < 0 && (*args).minus == 0)
	{
		g_rvalue++;
		ft_putchar('-');
	}
	if ((*args).moins == 0)
	{
		if ((*args).poz == 1 && (*args).precnm <= 0 && (*args).dig == 0)
			return ;
		g_rvalue = g_rvalue + cout_digit(*args);
		ft_putnbr_lib((*args).dig, *args);
	}
}

void	ft_putnbr_lib(intmax_t n, t_lt args)
{
	intmax_t			i;
	unsigned long long	g;

	g = 9223372036854775808U;
	i = n;
	if ((unsigned long long)i == g)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n == -1 && check_minusone_value(args) == 1)
		return ;
	if (i < 0)
		ft_putnbr(-i);
	else if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar((i % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

int		check_minusone_value(t_lt args)
{
	if (args.conv == 'u')
	{
		ft_putstr("18446744073709551615");
		g_rvalue = g_rvalue + ft_strlen("18446744073709551615") - 1;
		return (1);
	}
	return (0);
}

void	ft_printf_spaces(int i)
{
	while (i && i > 0)
	{
		g_rvalue++;
		ft_putchar(' ');
		i--;
	}
}

void	ft_printf_zero(int j)
{
	while (j && j > 0)
	{
		g_rvalue++;
		ft_putchar('0');
		j--;
	}
}

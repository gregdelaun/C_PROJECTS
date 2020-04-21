/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:06:53 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:32:09 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_fct g_tab[] =
{
	{&work_on_it_float, 'f'},
	{&work_on_it_pointeurs, 'p'},
	{&work_on_it_d, 'd'},
	{&work_on_it_d, 'i'},
	{&work_on_it_u, 'u'},
	{&work_on_it_s, 's'},
	{&work_on_it_c, 'c'},
	{&work_on_it_o, 'o'},
	{&work_on_it_big_x, 'X'},
	{&work_on_it_big_x, 'x'},
	{&work_on_it_pourcent, '%'},
	{NULL, -1}
};

void	open_specif(t_lt *args)
{
	if ((*args).h == 1)
		(*args).dig = (short)va_arg((*args).var, int);
	else if ((*args).hh == 1)
		(*args).dig = (signed char)va_arg((*args).var, int);
	else if ((*args).l == 1)
		(*args).dig = (long)va_arg((*args).var, long int);
	else if ((*args).ll == 1)
		(*args).dig = va_arg((*args).var, long long int);
	else if ((*args).j == 1)
		(*args).dig = (intmax_t)va_arg((*args).var, intmax_t);
	else if ((*args).modz == 1)
		(*args).dig = (size_t)va_arg((*args).var, size_t);
	else
		(*args).dig = (int)va_arg((*args).var, int);
}

t_lt	work_on_it_d(t_lt args)
{
	open_specif(&args);
	if (args.moins == 1)
		return (do_minus(&args));
	if (args.dig < 0 && args.plus == 0)
		args.width--;
	if (args.space == 1 && args.plus == 0)
		do_space(&args);
	if (args.plus == 1 && !(args.width > 0 || args.prec > 0))
		do_plus(&args);
	if (args.width > 0 && args.zero == 1 && args.moins == 0 && args.poz != 1)
		do_zero(&args);
	else if ((args.width > 0 || args.prec > 0))
		do_width(&args);
	other_stuffs(&args);
	return (args);
}

t_lt	ft_conversion(char *conv, int atc, int start, t_lt args)
{
	int i;

	i = 0;
	args.conv = 0;
	args = initialise_list(args);
	args.minus = 0;
	args.modz = 0;
	args.j = 0;
	ft_activate1_list(conv, start, &args);
	args.widthnm = args.width;
	args.precnm = args.prec;
	args.conv = conv[atc];
	if (args.conv == '%')
		args.t = atc;
	while (g_tab[i].key != -1)
	{
		if (g_tab[i].key == conv[atc])
			args = g_tab[i].ptr_fonc(args);
		i++;
	}
	return (args);
}

int		cout_digit(t_lt args)
{
	intmax_t			nb;
	unsigned long long	g;
	int					c;

	g = 9223372036854775808U;
	c = 1;
	nb = args.dig;
	if ((unsigned long long)nb == g)
		return (19);
	if (args.conv == 'o' || args.conv == 'x' || args.conv == 'X')
		return (ft_strlen(args.str) + ft_check_o_x_x(args));
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

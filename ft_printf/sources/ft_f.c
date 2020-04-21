/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:35:50 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 10:52:45 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*ftoa(long double f, int prec, t_lt args)
{
	uintmax_t	dec;
	uintmax_t	frac;
	char		*ret;
	int			dlen;
	uintmax_t	i;

	dec = f;
	frac = (f - dec) * check_power(10, prec) + 0.5;
	if (((int)((f - dec) * 10) > 4) && (!frac || check_frac(frac)))
		dec = dec + 1;
	i = dec;
	dlen = 1;
	while (i > 9 && dlen++)
		i /= 10;
	if (!(ret = ft_strnew(dlen + prec + 1)))
		return (0);
	ret = place_decimal(dlen - 1, ret, dec);
	prec > 0 || args.hash == 1 ? ret[dlen++] = '.' : 0;
	i = dlen + prec - 1;
	while (i > (unsigned)dlen - 1)
	{
		ret[i--] = (frac % 10) + '0';
		frac /= 10;
	}
	return (ret);
}

static	t_lt	check_args_values(t_lt args, char *str)
{
	args.width = args.width - ft_strlen(str);
	return (args);
}

t_lt			do_minus_for_float(t_lt args, char *str, int ng)
{
	if (ng == -1)
	{
		g_rvalue++;
		ft_putchar('-');
	}
	if ((args.plus == 1 || args.space == 1) && ng != -1)
	{
		g_rvalue++;
		if (args.plus == 1)
			ft_putchar('+');
		else
			ft_putchar(' ');
	}
	ft_putstr(str);
	g_rvalue = g_rvalue + ft_strlen(str);
	if (args.width > 0)
		while (args.width--)
		{
			ft_putchar(' ');
			g_rvalue++;
		}
	str ? free(str) : 0;
	return (args);
}

static	void	print_for_floats(t_lt args, int ng, char *str)
{
	if (args.zero == 0 && args.width > 0)
		while (args.width--)
		{
			ft_putchar(' ');
			g_rvalue++;
		}
	if (ng == -1)
	{
		ft_putchar('-');
		g_rvalue++;
	}
	if ((args.plus == 1 || args.space == 1) && ng != -1)
	{
		g_rvalue++;
		args.plus == 1 ? ft_putchar('+') : ft_putchar(' ');
	}
	if (args.zero == 1 && args.width > 0)
		while (args.width--)
		{
			ft_putchar('0');
			g_rvalue++;
		}
	ft_putstr(str);
	str ? free(str) : 0;
	g_rvalue = g_rvalue + ft_strlen(str);
}

t_lt			work_on_it_float(t_lt args)
{
	long double f;
	char		*str;
	int			ng;

	f = 0;
	args.str = NULL;
	if (args.bigl == 1)
		f = (long double)va_arg(args.var, long double);
	else
		f = (double)va_arg(args.var, double);
	if (args.prec == 0 && args.poz == 1)
		args.prec = 0;
	if (args.prec == 0 && args.poz != 1)
		args.prec = 6;
	ng = ((f < 0)) ? -1 : 1;
	f *= ng;
	str = ftoa(f, args.prec, args);
	(ng == -1 || args.plus == 1 || args.space == 1) ? args.width -= 1 : 0;
	args = check_args_values(args, str);
	if (args.moins == 1)
		return (do_minus_for_float(args, str, ng));
	print_for_floats(args, ng, str);
	return (args);
}

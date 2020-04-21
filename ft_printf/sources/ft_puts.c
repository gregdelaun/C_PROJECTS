/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:20:00 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 13:37:37 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	t_lt	check_before_percent(t_lt args)
{
	if (!(args.dis = ft_strsub(args.temp, args.g, args.i - args.g + 1)))
		exit(0);
	g_rvalue = g_rvalue + ft_strlen(args.dis);
	args.g = args.i + go_to_conversion2(args.temp, args.i + 1) + 2;
	if (args.temp[args.i] != '%')
		ft_puts(args.dis);
	free(args.dis);
	if (args.temp[args.i + 1] == '%'
	&& check_valid_conversion(args.temp, args.i + 1) == 0)
		(args = ft_conversion(args.temp,
				go_to_conversion(args.temp, args.i + 2), args.i + 1, args));
	if (args.temp[go_to_conversion(args.temp, args.i + 2)] == '%'
	&& !(args.temp[args.i + 1] == '\0')
	&& check_valid_conversion(args.temp, args.i + 1) == 0)
	{
		args.g = args.t + 1;
		args.i = args.t - 1;
	}
	if (args.temp[args.i + 2] != '\0')
		args.i++;
	return (args);
}

static	t_lt	check_on_percent(t_lt args)
{
	args.g = args.i + go_to_conversion2(args.temp, args.i + 1) + 2;
	if (check_valid_conversion(args.temp, args.i))
		args.g = go_till_next_for_print(args.temp, args.i);
	else
		args = ft_conversion(args.temp,
			go_to_conversion(args.temp, args.i + 1), args.i, args);
	if (args.temp[go_to_conversion(args.temp, args.i + 1)] == '%'
	&& check_valid_conversion(args.temp, args.i) == 0)
	{
		args.g = args.t + 1;
		args.i = args.t - 1;
	}
	args.i++;
	return (args);
}

int				ft_printf(const char *restrict format, ...)
{
	t_lt	args;
	int		c;
	int		p;

	p = 1;
	c = 0;
	args.g = 0;
	args.temp = (char *)format;
	g_rvalue = 0;
	args.i = 0;
	va_start(args.var, format);
	while (args.temp[args.i++])
	{
		if (c == 0)
			args.i = 0;
		if ((args.temp[args.i + 1] == '%' && args.temp[args.i] != '%')
		|| (args.temp[args.i + 1] == '\0' && args.temp[args.i] != '%'))
			args = check_before_percent(args);
		else if (args.temp[args.i] == '%')
			args = check_on_percent(args);
		c++;
	}
	va_end(args.var);
	return (g_rvalue);
}

int				go_till_next_for_print(char *temp, int i)
{
	i++;
	while (temp[i] && (is_a_specifier(temp[i]) == 1
		|| is_not_specific1(temp[i]) == 0))
	{
		i++;
	}
	return (i);
}

int				check_valid_conversion(char *temp, int i)
{
	i++;
	while (temp[i])
	{
		if ((temp[i] >= 'a' && temp[i] <= 'z')
			|| (temp[i] >= 'A' && temp[i] <= 'Z') || temp[i] == '%')
		{
			if (is_a_conversion(temp[i]) == 0)
				return (0);
			else if (is_a_specifier(temp[i]) != 0)
			{
				while (is_a_specifier(temp[i]) != 0)
					i++;
				i--;
			}
			else
				return (1);
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:01:33 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 14:01:56 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	work_on_it_u(t_lt args)
{
	open_specif_u(&args);
	if (args.moins == 1)
		return (do_minus(&args));
	if (args.dig < 0 && args.plus == 0)
		args.width--;
	if (args.width > 0 && args.zero == 1 && args.moins == 0 && args.prec == 0)
		do_zero(&args);
	else if ((args.width > 0 || args.prec > 0))
		do_width(&args);
	other_stuffs(&args);
	return (args);
}

void	open_specif_u(t_lt *args)
{
	if ((*args).h == 1)
		(*args).dig = (unsigned short)va_arg((*args).var, int);
	else if ((*args).hh == 1)
		(*args).dig = (unsigned char)va_arg((*args).var, int);
	else if ((*args).l == 1)
		(*args).dig = va_arg((*args).var, intmax_t);
	else if ((*args).ll == 1)
		(*args).dig = (unsigned long long)va_arg((*args).var, intmax_t);
	else if ((*args).j == 1)
		(*args).dig = va_arg((*args).var, uintmax_t);
	else if ((*args).modz == 1)
		(*args).dig = va_arg((*args).var, size_t);
	else
		(*args).dig = (unsigned int)va_arg((*args).var, unsigned int);
	(*args).str = NULL;
}

t_lt	work_on_it_p(t_lt args)
{
	return (args);
}

void	do_space(t_lt *args)
{
	if ((*args).dig >= 0 && (*args).conv != 'u')
	{
		ft_putchar(' ');
		g_rvalue++;
		(*args).width--;
	}
}

void	do_plus(t_lt *args)
{
	if ((*args).dig >= 0 && (*args).conv != 'u')
	{
		g_rvalue++;
		ft_putchar('+');
	}
	(*args).plus = 2;
	(*args).width--;
}

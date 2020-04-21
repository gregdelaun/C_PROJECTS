/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:55:08 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 13:59:47 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_lt	do_minus_for_s(t_lt args)
{
	if (args.prec < (int)ft_strlen(args.s) && args.prec)
	{
		ft_putstr_l((char*)args.s, args.prec);
		g_rvalue = g_rvalue + args.prec;
	}
	else
	{
		ft_putstr((char *)args.s);
		g_rvalue = g_rvalue + ft_strlen(args.s);
	}
	if (args.prec < (int)ft_strlen(args.s) && args.prec)
		args.width = args.width - args.prec;
	else
		args.width = args.width - ft_strlen(args.s);
	if (args.width > 0)
	{
		while (args.width)
		{
			ft_putchar(' ');
			g_rvalue++;
			args.width--;
		}
	}
	return (args);
}

t_lt	work_on_it_s(t_lt args)
{
	if (args.ll == 0)
	{
		if ((args.s = va_arg(args.var, const char*)) == NULL)
			args.s = "(null)";
	}
	else
	{
		if ((args.s = (const char *)va_arg(args.var, wchar_t *)) == NULL)
			args.s = "(null)";
	}
	if (args.moins == 1)
		return (do_minus_for_s(args));
	else
		g_rvalue = do_normal_s(args);
	if (args.prec < (int)ft_strlen(args.s) && args.poz == 1)
	{
		ft_putstr_l((char*)args.s, args.prec);
		g_rvalue = g_rvalue + args.prec;
	}
	else
	{
		ft_putstr((char *)args.s);
		g_rvalue = g_rvalue + ft_strlen(args.s);
	}
	return (args);
}

int		do_normal_s(t_lt args)
{
	if (args.prec < (int)ft_strlen(args.s) && args.poz == 1)
		args.width = args.width - args.prec;
	else
		args.width = args.width - ft_strlen(args.s);
	if (args.width > 0)
	{
		while (args.width)
		{
			ft_putchar(' ');
			g_rvalue++;
			args.width--;
		}
	}
	return (g_rvalue);
}

void	ft_putstr_l(const char *str, int l)
{
	int i;

	i = 0;
	while (l && str[i] && l > 0)
	{
		ft_putchar(str[i]);
		i++;
		l--;
	}
}

char	*ft_toa_base_2(intmax_t value, int base)
{
	static	char		*hex;
	char				*result;
	intmax_t			n;
	int					len;

	n = value;
	hex = "0123456789abcdef";
	if (value == -1 || value == -4294967297 || value == -4294967296
		|| value == 0)
		return (return_string_spec(value));
	len = ft_len_base(n, base);
	if (!(result = (char*)malloc(len + 1)))
		exit(0);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = hex[n % base];
		n /= base;
	}
	return (result);
}

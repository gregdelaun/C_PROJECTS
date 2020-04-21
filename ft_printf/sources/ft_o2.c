/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:36:42 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 13:04:02 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_len_base(intmax_t value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

void	ft_check_o(t_lt args)
{
	if (args.hash == 1 && args.conv == 'x' && args.dig != 0)
	{
		ft_putstr("0x");
		g_rvalue = g_rvalue + 2;
	}
	if (args.hash == 1 && args.conv == 'X' && args.dig != 0)
	{
		ft_putstr("0X");
		g_rvalue = g_rvalue + 2;
	}
}

int		ft_check_o_x_x(t_lt args)
{
	if (args.dig == 0 && args.prec > 0)
		return (0);
	if (args.hash == 1 && args.conv == 'o' && (args.dig != 0 || args.poz == 1))
		return (1);
	if (args.hash == 1 && args.conv == 'x' && args.dig != 0)
		return (2);
	if (args.hash == 1 && args.conv == 'X')
		return (2);
	return (0);
}

char	*ft_toa_base_(intmax_t value, int base, t_lt args)
{
	static char			*hex;
	char				*result;
	intmax_t			n;
	int					len;

	hex = "0123456789ABCDEF";
	n = value;
	if (value == -1)
		return (ft_strdup(return_max_string(args)));
	if (value < 0 && args.conv == 'o')
		return (ft_strdup("1000000000000000000000"));
	if (value < 0 && args.conv == 'X')
		return (ft_strdup("8000000000000000"));
	if (value == 0)
		return (ft_strdup("0"));
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

char	*return_max_string(t_lt args)
{
	if (args.conv == 'X')
		return ("FFFFFFFFFFFFFFFF");
	if (args.conv == 'o')
		return ("1777777777777777777777");
	return (NULL);
}

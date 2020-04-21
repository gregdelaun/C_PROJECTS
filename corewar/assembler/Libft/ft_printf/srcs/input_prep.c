/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:30:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:31:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	precision(t_ft *input, const char *format, int *i)
{
	if (format[*i] == '.')
	{
		input->dot = 1;
		*i += 1;
		if (format[*i] == '*')
		{
			input->prec = va_arg(input->vl, int);
			*i += 1;
		}
		else if (ft_isdigit(format[*i]))
		{
			input->prec = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				*i += 1;
		}
		else
			input->prec = 0;
	}
	else
	{
		if (ft_isprintfflag(format[*i]) != 1 && format[*i] != '\0')
			*i += 1;
	}
	if (input->prec < 0)
		input->dot = 0;
}

static void	width(t_ft *input, const char *format, int *i)
{
	if (input->align == '-')
		input->pad = ' ';
	if ((input->f == 'D' || input->f == 'd' || input->f == 'i')\
	&& format[*i] == '0' && *i - 1 >= 0 && format[*i - 1] == '-')
		input->pad = ' ';
	if ((ft_isdigit(format[*i]) || \
	(format[*i] == '-' && ft_isdigit(format[*i + 1])))\
	&& format[*i] != '\0')
	{
		if (format[*i] == '-')
			input->align = '-';
		input->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]) || \
		(format[*i] == '-' && ft_isdigit(format[*i + 1])))
			*i += 1;
	}
	if (format[*i] == '*')
		input->width = va_arg(input->vl, int);
	if (input->width < 0)
		input->align = '-';
	if (format[*i] == '+')
		input->sign = 1;
}

static void	length(t_ft *input, const char *format, int *i)
{
	if (format[*i] == 'l')
		input->l += 1;
	else if (format[*i] == 'L')
		input->l = 3;
	else if (format[*i] == 'j')
		input->j = 1;
	else if (format[*i] == 'z')
		input->z = 1;
	else if (format[*i] == 'h')
		input->h += 1;
}

static void	flags(t_ft *input, const char *format, int *i)
{
	if (format[*i] == '#')
		input->hash = 1;
	else if (format[*i] == '0')
		input->pad = '0';
	else if (format[*i] == '-')
		input->align = '-';
	else if (format[*i] == '+')
		input->sign = 1;
	else if (format[*i] == ' ')
		input->space = 1;
}

void		inprep(t_ft *input, const char *format, int *i)
{
	int	j;

	j = *i;
	input = inreset(input);
	while (ft_isprintfflag(format[j]) == 0 && format[j] != '\0')
		j++;
	if ((input->f = format[j]) != '\0')
	{
		while (ft_isprintfflag(format[*i]) == 0 && format[*i] != '\0')
		{
			flags(input, format, i);
			length(input, format, i);
			width(input, format, i);
			precision(input, format, i);
		}
	}
}

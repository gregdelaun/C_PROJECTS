/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:03 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:27:10 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	no_prec_e(t_ft *input)
{
	double		in;
	long double	lin;

	if (input->l == 0)
	{
		in = va_arg(input->vl, double);
		if (in >= 100000)
			ft_scinot(in, input->after, input->temp, input->temp2);
		else
			pt_ftoa(in, input->after / 2, input->temp, input->temp2);
	}
	else
	{
		lin = va_arg(input->vl, long double);
		if (lin >= 100000)
			ft_scinot_l(lin, input->after, input->temp, input->temp2);
		else
			pt_ftoa_l(lin, input->after / 2, input->temp, input->temp2);
	}
}

static void	put_prec_e(t_ft *input)
{
	double		in;
	long double	lin;

	if (input->l == 0)
	{
		in = va_arg(input->vl, double);
		if (in >= 100000)
			ft_scinot(in, input->prec - 1, input->temp, input->temp2);
		else
			pt_ftoa(in, input->prec, input->temp, input->temp2);
	}
	else
	{
		lin = va_arg(input->vl, double);
		if (lin >= 100000)
			ft_scinot_l(lin, input->prec - 1, input->temp, input->temp2);
		else
			pt_ftoa_l(lin, input->prec, input->temp, input->temp2);
	}
}

static void	g_input(t_ft *input)
{
	if (input->dot == 0)
		no_prec_e(input);
	else
		put_prec_e(input);
}

void		ft_g_out(t_ft *input, int *j)
{
	g_input(input);
	if (input->hash == 1 && input->dot == 1 && input->prec == 0)
		input->temp[ft_strlen(input->temp)] = '.';
	if (input->f == 'G')
		input->temp = ft_strtoupper(input->temp);
	space_sign_placer(input);
	widthconv_str(input, j);
}

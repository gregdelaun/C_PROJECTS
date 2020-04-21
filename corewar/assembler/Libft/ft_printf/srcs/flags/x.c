/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:40 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:50:41 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	hex_input(t_ft *input)
{
	if (input->j == 1)
		input->temp = pt_inttohexastr_j(va_arg(input->vl, intmax_t),\
		input->hash, input->temp, input->temp2);
	else if (input->l == 2)
		input->temp = pt_inttohexastr_ll(va_arg(input->vl, unsigned long long),\
		input->hash, input->temp, input->temp2);
	else if (input->z == 1)
		input->temp = pt_inttohexastr_z(va_arg(input->vl, size_t),\
		input->hash, input->temp, input->temp2);
	else if (input->l == 1)
		input->temp = pt_inttohexastr_l(va_arg(input->vl, unsigned long),\
		input->hash, input->temp, input->temp2);
	else if (input->h == 1)
		input->temp = pt_inttohexastr_h(va_arg(input->vl, unsigned int),\
		input->hash, input->temp, input->temp2);
	else if (input->h == 2)
		input->temp = pt_inttohexastr_hh(va_arg(input->vl, unsigned int),\
		input->hash, input->temp, input->temp2);
	else
		input->temp = pt_inttohexastr(va_arg(input->vl, unsigned int),\
		input->hash, input->temp, input->temp2);
}

void		ft_hex_out(t_ft *input, int *j)
{
	hex_input(input);
	if (input->f == 'X')
		input->temp = ft_strtoupper(input->temp);
	if (input->dot == 1)
		put_prec_dioux(input);
	widthconv_str(input, j);
}

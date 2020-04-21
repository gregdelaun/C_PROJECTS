/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:07 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:27:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	n_out(int *out, int *j)
{
	*out = *j;
}

static void	n_out_j(intmax_t *out, int *j)
{
	*out = *j;
}

void		ft_n(t_ft *input, int *j)
{
	if (input->l == 1)
		n_out_l(va_arg(input->vl, long *), j);
	else if (input->l == 2 || input->f == 'N')
		n_out_ll(va_arg(input->vl, long long *), j);
	else if (input->h == 1)
		n_out_h(va_arg(input->vl, short *), j);
	else if (input->h == 2)
		n_out_hh(va_arg(input->vl, signed char *), j);
	else if (input->z == 1)
		n_out_z(va_arg(input->vl, size_t *), j);
	else if (input->j == 1)
		n_out_j(va_arg(input->vl, intmax_t *), j);
	else
		n_out(va_arg(input->vl, int *), j);
}

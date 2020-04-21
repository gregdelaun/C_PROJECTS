/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:14:53 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:15:09 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	n_out_l(long *out, int *j)
{
	*out = *j;
}

void	n_out_ll(long long *out, int *j)
{
	*out = *j;
}

void	n_out_h(short *out, int *j)
{
	*out = *j;
}

void	n_out_hh(signed char *out, int *j)
{
	*out = *j;
}

void	n_out_z(size_t *out, int *j)
{
	*out = *j;
}

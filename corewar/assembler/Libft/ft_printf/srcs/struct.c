/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:34:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/05 13:34:17 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_ft		*initstruct(t_ft *input)
{
	if (!(input->buff = ft_strnew(OPEN_MAX)) \
	|| !(input->temp = ft_strnew(OPEN_MAX)) \
	|| !(input->temp2 = ft_strnew(OPEN_MAX)))
		return (0);
	input->fd = 1;
	input->c0 = 0;
	return (input);
}

t_ft		*inreset(t_ft *input)
{
	ft_memset(input->temp, '\0', OPEN_MAX);
	ft_memset(input->temp2, '\0', OPEN_MAX);
	input->width = 0;
	input->after = 6;
	input->pad = ' ';
	input->f = '\0';
	input->hash = 0;
	input->space = 0;
	input->sign = 0;
	input->l = 0;
	input->h = 0;
	input->z = 0;
	input->j = 0;
	input->dot = 0;
	input->align = '+';
	return (input);
}

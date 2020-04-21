/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:33:26 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:30:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		sign_replacer(t_ft *input)
{
	int i;

	i = 0;
	while ((input->temp[i] != '-' && input->temp[i] != '+')\
	&& input->temp[i] != '\0')
		i++;
	if (input->temp[i] != '\0' && input->temp[0] == '0')
		ft_charswap(&input->temp[i], &input->temp[0]);
}

static char	*ft_place_x(char *temp)
{
	int i;

	i = ft_strlen(temp);
	while (--i >= 0)
		if (temp[i] == 'x' || temp[i] == 'X')
			break ;
	ft_charswap(&temp[i], &temp[1]);
	return (temp);
}

void		put_prec_dioux(t_ft *input)
{
	int i;

	if (input->prec == 0 && input->temp[0] == '0' && input->temp[1] == '\0')
		ft_strclr(input->temp);
	else if (input->prec > (int)ft_strlen(input->temp))
	{
		i = input->prec - (int)ft_strlen(input->temp);
		if (input->temp[0] == '-')
			i++;
		if ((input->f == 'x' || input->f == 'X') && input->hash == 1)
			i += 2;
		input->temp2 = ft_strcpy(input->temp2, input->temp);
		ft_strclr(input->temp);
		while (--i >= 0)
			input->temp[i] = '0';
		input->temp = ft_strcat(input->temp, input->temp2);
	}
	if ((input->f == 'x' || input->f == 'X') && input->hash == 1)
		input->temp = ft_place_x(input->temp);
	if (input->temp[0] == '\0')
		input->pad = ' ';
}

void		widthconv_c(t_ft *input, int *j, int c)
{
	int	x;

	x = ft_intmakepos(input->width);
	ft_memset(input->temp, input->pad, x);
	if (input->width > 0)
		input->temp[input->width - 1] = c;
	else
		input->temp[0] = c;
	if (c != 0)
		input->buff = ft_strncat(input->buff, input->temp, input->width);
	else
		input->buff = ft_strncat_c0(input->buff, input->temp, input->width,\
		input->c0);
	*j += x;
}

void		widthconv_str(t_ft *input, int *j)
{
	int i;

	i = ft_intmakepos(input->width);
	if ((int)ft_strlen(input->temp) < i)
	{
		ft_memcpy(input->temp2, input->temp, ft_strlen(input->temp));
		if (input->align == '+')
			right_align(input, i);
		else if (input->align == '-')
			left_align(input, i);
		if (input->hash == 1 && input->pad == '0' && input->f == 'x')
			input->temp = ft_place_x(input->temp);
		input->buff = ft_strncat(input->buff, input->temp, input->width);
		*j += i;
	}
	else
		no_align(input, j);
}

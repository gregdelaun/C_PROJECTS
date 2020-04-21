/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:27:27 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/02/07 10:42:32 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	delall(t_ft *input)
{
	if (input->buff)
		ft_strdel(&input->buff);
	if (input->temp)
		ft_strdel(&input->temp);
	if (input->temp2)
		ft_strdel(&input->temp2);
	if (input)
		ft_memdell(input);
}

static void	parser2(t_ft *input, int *j)
{
	if (input->f == 'd' || input->f == 'i' || input->f == 'D')
		ft_dec_out(input, j);
	else if (input->f == 'f' || input->f == 'F')
		ft_f_out(input, j);
	else if (input->f == 'g' || input->f == 'G')
		ft_g_out(input, j);
	else if (input->f == 'e' || input->f == 'E')
		ft_e_out(input, j);
	else if (input->f == 'o' || input->f == 'O')
		ft_o_out(input, j);
	else if (input->f == 'x' || input->f == 'X')
		ft_hex_out(input, j);
	else if (input->f == 'u' || input->f == 'U')
		ft_u_out(input, j);
	else if (input->f == 'b')
		ft_b_out(input, j);
}

static void	parser(t_ft *input, int *j)
{
	if (input->f == '%')
		ft_percentage(input, j);
	else if (input->f == 'c' || input->f == 'C')
		ft_char_out(va_arg(input->vl, int), input, j);
	else if (input->f == 's' || input->f == 'S')
		ft_str_out(input, j);
	else if (input->f == 'p' || input->f == 'P')
		ft_p_out(input, j);
	else if (input->f == 'n')
		ft_n(input, j);
	else if (input->f == 't' || input->f == 'T')
		ft_fd(input);
	else
		parser2(input, j);
}

static void	ft_parse(t_ft *input, const char *format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				i++;
				inprep(input, format, &i);
				if (input->f != '\0')
					parser(input, &j);
			}
		}
		else
		{
			input->buff[j] = format[i];
			j++;
		}
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_ft	*input;
	int		i;

	if (!(input = ft_memalloc(sizeof(t_ft))))
		return (-1);
	input = initstruct(input);
	va_start(input->vl, format);
	ft_parse(input, format);
	va_end(input->vl);
	i = ft_strlen_c0(input->buff, input->c0);
	ft_putstr_fd_c0(input->buff, input->fd, input->c0);
	if (input)
		delall(input);
	return (i);
}

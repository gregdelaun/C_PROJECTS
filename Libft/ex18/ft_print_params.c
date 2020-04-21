/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:12:39 by grde-lau          #+#    #+#             */
/*   Updated: 2018/11/28 11:17:59 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int i;
	int j;
	int nbrp;

	i = 1;
	j = 0;
	nbrp = argc - 1;
	while (nbrp != 0)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		nbrp--;
		i++;
	}
	return (0);
}

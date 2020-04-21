/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chararrprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:15:48 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/10 16:15:49 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../../ft_printf/includes/ft_printf.h"

void			ft_chararrprint(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		ft_printf("%s\n", arr[i]);
}

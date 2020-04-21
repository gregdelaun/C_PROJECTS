/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/10 13:42:06 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <time.h>

/*
**  Returns a randon number between 0 and max
*/

int	ft_random(int max)
{
	int	i;

	i = 0;
	i = rand() % max;
	return (i);
}

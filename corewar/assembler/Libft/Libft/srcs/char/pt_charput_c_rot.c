/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_charput_c_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:51:49 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:51:50 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pt_charput_c_rot(char **str, char c, int pos, int rot)
{
	pt_strrot(str, rot);
	*str[pos] = c;
}

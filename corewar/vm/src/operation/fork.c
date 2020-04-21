/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <tjuzen@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:51:26 by tjuzen            #+#    #+#             */
/*   Updated: 2020/02/07 15:57:16 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//		fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée
//		un nouveau processus, qui hérite des différents états de son père, à part son PC,
//		qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

#include "../../includes/corewar.h"

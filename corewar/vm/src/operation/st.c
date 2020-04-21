/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <tjuzen@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:52:30 by tjuzen            #+#    #+#             */
/*   Updated: 2020/02/07 16:01:52 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//		st : Prend un registre et un registre ou un indirect, et stocke la valeur du registre
//		vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke la
//		valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

#include "../../includes/corewar.h"

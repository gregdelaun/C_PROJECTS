/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <tjuzen@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:52:37 by tjuzen            #+#    #+#             */
/*   Updated: 2020/02/07 16:02:47 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//		aff : L’opcode est 10 en hexadécimal. Il y a un octet de codage des paramètres,
//		même si c’est un peu bête car il n’y a qu’un paramètre, qui est un registre, dont
//		le contenu est interprété comme la valeur ASCII d’un caractère à afficher sur la
/		sortie standard. Ce code est modulo 256.
*/

#include "../../includes/corewar.h"

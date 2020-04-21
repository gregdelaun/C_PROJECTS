/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:13:31 by bsuarez-          #+#    #+#             */
/*   Updated: 2020/03/03 17:55:34 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int check_kill(int cycles, t_process *tmp, t_main *struk)
{
    if (tmp->last_live == -1)
        return (1);
    if (((tmp->last_live - cycles) * -1) <= struk->nbr_cycles + CYCLE_DELTA)
    {
        // printf("XXXX____: %d | %d\n", ((tmp->last_live - cycles) * -1), struk->nbr_cycles + CYCLE_DELTA);
        return (0);
    }
    // printf("FINISH____: %d | %d\n", ((tmp->last_live - cycles) * -1), struk->nbr_cycles + CYCLE_DELTA);

    return (1);
}

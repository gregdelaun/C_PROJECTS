/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:13:38 by bsuarez-          #+#    #+#             */
/*   Updated: 2020/03/03 17:53:17 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void init_all_rules(t_main *struk)
{
    int i;
    t_arena *init;

    if (!(init = ft_memalloc(sizeof(t_arena))))
        leave("Failed malloc of arena");
    struk->map = init;
    i = 1;
    struk->nbr_cycles = CYCLE_TO_DIE;
    struk->max_cycle = 0;
    struk->die = 0;
    struk->last_player = -1;
    struk->cycles = 0;
    struk->inter_cycles = 0;
    struk->checks_num = 0;
    struk->lives_num = 0;
    struk->nbr_cursor = 0;
    i = -1;
    while (++i < MEM_SIZE)
        struk->map->cursor_map[i] = 0;
    i = 1;
    while (i < struk->nbr_player + 1)
    {
        init_cursor(struk, i);
        struk->nbr_cursor++;
        i++;
    }
    i = -1;
    while (++i < MEM_SIZE)
        struk->map->arena[i] = 0;
    i = -1;
    while (++i < MEM_SIZE)
        struk->map->code_property[i] = 0;
    struk->map->maxcols = 1;
    struk->map->maxlines = LINES - 1;
    struk->map->warena = newwin(68, 200, 0, 0);
    struk->map->winfos = newwin(68, 55, 0, 200);
    struk->map->is_running = 0;
    struk->map->speed = DEFAULT_SPEED;
    struk->map->cursor_pos = 0;
    struk->map->button = 0;
    box(struk->map->warena, '*', '*');
    box(struk->map->winfos, '*', '*');
    // Initier les premier curseur en fonction de l'ordre établis dans le parsing
}

// On réinitialise nos variables entre deux CYCLE_TO_DIE

void upload_rules_var(t_main *struk)
{
    struk->nbr_cycles -= CYCLE_DELTA; // Si on a décrémenter ça veut dire,
    struk->max_cycle = 0;
    struk->lives_num = 0;
    struk->die = 1; // qu'on peut tuer les process qui n'on pas dis live.
}

void refresh_cursor(t_main *struk, t_process *tmp, int cycles)
{
    // tmp->id = 0;
    // tmp->carry = 0;
    // tmp->position = 0;
    tmp->last_live = 24000;
    // tmp->wait_cycles = 75;
    // tmp->jump = 0;
    // tmp->registeries[REG_NUMBER] = 0;
}

void init_cursor(t_main *struk, int id)
{
    t_process *cursor;
    int i;
    if (!(cursor = ft_memalloc(sizeof(t_process))))
        leave("maloc cursor failed");
    cursor->id = id;
    cursor->carry = false;
    cursor->opcodes = -1;
    cursor->position = check_position_to_start(struk, id);
    struk->map->cursor_map[cursor->position] = 1;
    cursor->wait_cycles = 0;
    cursor->jump = 0;
    cursor->last_live = -1;
    i = 1;
    while (i < REG_NUMBER)
        cursor->registeries[i++] = 0;
    cursor->registeries[0] = -id;
    if (struk->agent == NULL)
        struk->agent = cursor;
    else
    {
        cursor->next = struk->agent;
        struk->agent = cursor;
    }
}

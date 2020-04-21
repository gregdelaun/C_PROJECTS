/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:06 by tjuzen            #+#    #+#             */
/*   Updated: 2020/02/18 14:08:07 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

/*
** Cree mes deux windows
*/

void init_ncurses(t_main *struk)
{
    initscr();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    curs_set(false);
    cbreak();
    noecho();
    start_color();
    init_colorpairs();
    signal(SIGWINCH, NULL);
}

/*
** Kill les deux windows et exit ncurses
*/

void end_ncurses(t_main *struk)
{
    delwin(struk->map->warena);
    delwin(struk->map->winfos);
    endwin();
}

void handle_input(t_main *struk)
{
    if (struk->map->button == SPACE)
        struk->map->is_running = !struk->map->is_running;
    else if (struk->map->button == SPEED_UP_10)
        struk->map->speed += 10;
    else if (struk->map->button == SPEED_UP_100)
        struk->map->speed += 100;
    else if (struk->map->button == SPEED_DOWN_10)
        struk->map->speed -= 10;
    else if (struk->map->button == SPEED_DOWN_100)
        struk->map->speed -= 100;
    else if (struk->map->button == SPEED_DEFAULT)
        struk->map->speed = DEFAULT_SPEED;
}

void exec_instr(t_main *struk)
{
    main_while(struk);
}

int calc_time_delay(t_main *struk)
{
    return (CLOCKS_PER_SEC / struk->map->speed);
    // return (vm->vs->time + CLOCKS_PER_SEC / vm->vs->speed);
}
void main_visu(t_main *struk)
{
    while ((struk->map->button = getch()) != ESC)
    {
        handle_input(struk);
        if (struk->map->is_running == 1 /*&& (clock() >= calc_time_delay(struk))*/)
            exec_instr(struk);
        print_all(struk);
    }
}
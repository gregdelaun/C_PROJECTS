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

short curs_color(int fg)
{
    switch (7 & fg)
    {
    case 0:
        return (COLOR_BLACK);
    case 1:
        return (COLOR_BLUE);
    case 2:
        return (COLOR_GREEN);
    case 3:
        return (COLOR_CYAN);
    case 4:
        return (COLOR_RED);
    case 5:
        return (COLOR_MAGENTA);
    case 6:
        return (COLOR_YELLOW);
    case 7:
        return (COLOR_WHITE);
    }
    return (COLOR_BLACK);
}

int colornum(int fg, int bg)
{
    int B, bbb, ffff;

    B = 1 << 7;
    bbb = (7 & bg) << 4;
    ffff = 7 & fg;

    return (B | bbb | ffff);
}

void init_colorpairs(void)
{
    int fg, bg;
    int colorpair;

    for (bg = 0; bg <= 7; bg++)
    {
        for (fg = 0; fg <= 7; fg++)
        {
            colorpair = colornum(fg, bg);
            init_pair(colorpair, curs_color(fg), curs_color(bg));
        }
    }
}

void setcolor(int fg, int bg, t_main *struk)
{
    wattron(struk->map->winfos, COLOR_PAIR(colornum(fg, bg)));
    wattron(struk->map->warena, COLOR_PAIR(colornum(fg, bg)));
}

void unsetcolor(int fg, int bg, t_main *struk)
{
    wattroff(struk->map->winfos, COLOR_PAIR(colornum(fg, bg)));
    wattroff(struk->map->warena, COLOR_PAIR(colornum(fg, bg)));
}

/*
** Affiche l'etat de la memoire dans la window principale en bouclant dessus et en l'affichant en hexadecimal
*/

void write_colors(int fg, int bg, t_main *struk, int i, int j, int z)
{
    setcolor(bg, fg, struk);
    mvwprintw(struk->map->warena, i + 2, j + 1, "%02x", struk->map->arena[z++]);
    unsetcolor(fg, bg, struk);
}

void print_arena(t_main *struk)
{
    int i;
    int j;
    int z;
    int x;

    x = 0;
    i = 0;
    j = 3;
    z = 0;

    while (i < 64)
    {
        j = 3;
        x = 0;
        while (x < 64)
        {
            if (struk->map->code_property[z] == 1)
            {
                if (struk->map->cursor_map[z] != 1)
                    write_colors(0, 3, struk, i, j, z++);
                else
                    write_colors(3, 0, struk, i, j, z++);
            }
            else if (struk->map->code_property[z] == 2)
            {
                if (struk->map->cursor_map[z] != 1)
                    write_colors(0, 4, struk, i, j, z++);
                else
                    write_colors(4, 0, struk, i, j, z++);
            }
            else if (struk->map->code_property[z] == 3)
            {
                if (struk->map->cursor_map[z] != 1)
                    write_colors(0, 5, struk, i, j, z++);
                else
                    write_colors(5, 0, struk, i, j, z++);
            }
            else if (struk->map->code_property[z] == 4)
            {
                if (struk->map->cursor_map[z] != 1)
                    write_colors(0, 6, struk, i, j, z++);
                else
                    write_colors(6, 0, struk, i, j, z++);
            }
            else
            {
                if (struk->map->cursor_map[z] != 1)
                    write_colors(0, 7, struk, i, j, z++);
                else
                    write_colors(7, 0, struk, i, j, z++);
            }
            j += 3;
            x++;
        }
        i++;
    }
}

/*
** Nous affiche un COREWAR clignotant et brillant de milles feu
*/

void print_header(t_main *struk)
{
    setcolor(12, 0, struk);
    wattron(struk->map->winfos, A_BLINK);
    mvwprintw(struk->map->winfos, 2, 3, " ####   ####  #####  ###### #    #   ##   #####  ");
    mvwprintw(struk->map->winfos, 3, 3, "#    # #    # #    # #      #    #  #  #  #    # ");
    mvwprintw(struk->map->winfos, 4, 3, "#      #    # #    # #####  #    # #    # #    # ");
    mvwprintw(struk->map->winfos, 5, 3, "#      #    # #####  #      # ## # ###### #####  ");
    mvwprintw(struk->map->winfos, 6, 3, "#    # #    # #   #  #      ##  ## #    # #   #  ");
    mvwprintw(struk->map->winfos, 7, 3, " ####   ####  #    # ###### #    # #    # #    # ");
    wattroff(struk->map->winfos, A_BLINK);
    unsetcolor(12, 0, struk);
}

void print_buttons(t_main *struk)
{
    wattron(struk->map->winfos, A_BOLD);
    mvwprintw(struk->map->winfos, 23, 3, "SPACE : PLAY");
    mvwprintw(struk->map->winfos, 24, 3, "T     : INCREASE SPEED + 10");
    mvwprintw(struk->map->winfos, 25, 3, "Y     : INCREASE SPEED + 100");
    mvwprintw(struk->map->winfos, 26, 3, "W     : DECREASE SPEED - 10");
    mvwprintw(struk->map->winfos, 27, 3, "Q     : DECREASE SPEED - 100");
    mvwprintw(struk->map->winfos, 28, 3, "D     : DEFAULT SPEED");
    mvwprintw(struk->map->winfos, 29, 1, "_____________________________________________________");
    wattroff(struk->map->winfos, A_BOLD);
}
/*
** Window de droite, affiche les infos sur la partie en cours
*/

void print_this_player(t_main *struk, int player, int x)
{
    setcolor(player + 3, 0, struk);
    mvwprintw(struk->map->winfos, x, 3, "Player -%i : %s", player + 1, struk->player[player].name);
    unsetcolor(player + 3, 0, struk);
    mvwprintw(struk->map->winfos, x + 1, 3, "   Last live : 0");
    mvwprintw(struk->map->winfos, x + 2, 3, "   Lives in current period : 0");
}

void print_players(t_main *struk)
{
    int player;
    int x;

    player = -1;
    x = 31;
    wattron(struk->map->winfos, A_BOLD);
    while (++player < struk->nbr_player)
    {
        print_this_player(struk, player, x);
        x += 3;
    }
    mvwprintw(struk->map->winfos, 43, 1, "_____________________________________________________");
    wattroff(struk->map->winfos, A_BOLD);
}

void print_globals(t_main *struk)
{
    wattron(struk->map->winfos, A_BOLD);
    mvwprintw(struk->map->winfos, 8, 1, "_____________________________________________________");
    mvwprintw(struk->map->winfos, 10, 3, "Cycle         : %i", 0);
    mvwprintw(struk->map->winfos, 12, 3, "Processes     : %i", 0);
    mvwprintw(struk->map->winfos, 14, 3, "Cycles to die : %i", struk->nbr_cycles);
    mvwprintw(struk->map->winfos, 16, 3, "Cycle delta   : %i", struk->max_cycle);
    mvwprintw(struk->map->winfos, 18, 3, "Nbr live      : %i", struk->agent->last_live);
    mvwprintw(struk->map->winfos, 20, 3, "Max checks    : %i", MAX_CHECKS);
    mvwprintw(struk->map->winfos, 21, 1, "_____________________________________________________");
    wattroff(struk->map->winfos, A_BOLD);
    mvaddstr(struk->map->maxlines, 0, "Press escape to quit");
}

void print_infos(t_main *struk)
{
    print_header(struk);
    print_buttons(struk);
    print_players(struk);
    print_globals(struk);
}

void print_box(t_main *struk)
{
    box(struk->map->winfos, '*', '*');
    box(struk->map->warena, '*', '*');
}
void print_all(t_main *struk)
{
    werase(struk->map->winfos);
    werase(struk->map->warena);
    print_arena(struk);
    print_infos(struk);
    print_box(struk);
    wrefresh(struk->map->winfos);
    wrefresh(struk->map->warena);
}
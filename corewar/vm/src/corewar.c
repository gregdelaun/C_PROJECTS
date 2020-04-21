/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <tjuzen@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:10 by tjuzen            #+#    #+#             */
/*   Updated: 2020/02/24 14:23:26 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** Recupere les executable code des champions et les stockes dans  l'arene (la memoire)
*/

void load_champ_to_arena(t_main *struk) // en attente de la fonction de greg
{
	int i;
	int p;
	int start;
	int j;
	int nplayer;

	nplayer = struk->nbr_player;
	i = 0;
	p = 1;
	j = -1;
	start = MEM_SIZE / struk->nbr_player;
	while (struk->nbr_player > 0)
	{
		i = start * (p - 1);
		while (++j < struk->player[p - 1].code_length)
		{
			struk->map->arena[i] = struk->player[p - 1].code[j];
			struk->map->code_property[i] = p;
			i++;
		}
		j = -1;
		p++;
		struk->nbr_player--;
	}
	struk->nbr_player = nplayer;
}

/*
** S'occupe de tout le parsing
*/

void go_parse(t_main *struk, int argc, char **argv)
{
	int fd;
	int num_play;
	int i;

	num_play = 0;
	i = 0;
	while(++i < 4)
		struk->order_player[i][0] = 0;
	struk->nbr_player = 0;
	i = -1;
	if (argc <= 1)
		leave("Il nous faut des paramètres !");
	if (argc > 1)
		struk = check_arguments(argc, argv, struk); // simplement checker ce que l'on recçoit en argv
		while (++i < argc)
		{
			if (check_if_file(argv, i)) // si c'est un fichier ".cor"
			{
				fd = open_files(argc, argv, struk, i);						   // ouvre le fichier
				some_parsing_checks(fd, struk, num_play);					   // voir fonction
				some_other_parsing(fd, struk, num_play);					   // voir fonction
				struk->player[num_play].ID = struk->order_player[num_play][0]; // Donne l'ID a la structure du joueur (qu'on avait avant mis dans une array 2D)
				num_play++;
				struk->nbr_player++;
			}
		}
}

int rules_round(t_main *struk)
{
    init_all_rules(struk);
    printf("nbr_cycles: %i\n", struk->nbr_cycles);
    // if (struk->visu == 1)
    //     main_visu(struk);
    // else
    // {
    //     //print_map(struk);
    main_while(struk);
    printf("LAST_PLAYER: %d\n", struk->last_player);
    // }
    return (1);
}

int main(int argc, char **argv)
{
	t_main struk;

	go_parse(&struk, argc, argv);
	// if (struk.visu == 1)
	// 	init_ncurses(&struk);
	if (struk.nbr_player < 1 || struk.nbr_player > 4)
		leave("Champs : between 1 and 4");
	rules_round(&struk);
	// if (struk.visu == 1)
	// 	end_ncurses(&struk);
	return (0);
}

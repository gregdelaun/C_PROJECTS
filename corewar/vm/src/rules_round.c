/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuarez- <bsuarez-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:13:26 by bsuarez-          #+#    #+#             */
/*   Updated: 2020/03/03 17:55:13 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"


t_process *kill_cursor(t_main *struk, t_process *prev)
{
    t_process *tmp;

    // printf("CYCLES: %d\n", struk->nbr_cycles);
    if (prev == NULL)
    {
        // printf("IF__ tmp_id: ____ %d  ", struk->agent->id);
        // printf("JE TUE BRAAAAH BRHH! ____\n");
        tmp = struk->agent->next;
        // je link avec le début de la liste, c'est le premniere element qu'on kill
        free(struk->agent);
        struk->agent = tmp;
        return (struk->agent);
    }
    else
    {
        tmp = prev->next;
        // printf("ELSE tmp_id: ____ %d  ", tmp->id);
        // printf("JE TUE BRAAAAH BRHH! ____\n");
        // je relink et je delete le curseur
        prev->next = tmp->next;
        free(tmp);
        return (prev->next);
    }
    // printf("JE TUE BRAAAAH BRHH! ____\n");
    return (struk->agent);
    // Tuer les process qui ne sont plus en vie, et le relier a la liste.
}

void	move_cursor(t_main *struk, t_process *cursor)
{
	cursor->position += cursor->step;
	cursor->position = calc_addr(cursor->position);
	cursor->step = 0;
	ft_bzero(cursor->args_type, 3);
}

int check_operation(t_main *struk, t_process *cursor)
{
    t_op *op;
    op = NULL;
    if (cursor->opcodes >= 0x01 && cursor->opcodes <= 0x10)
    	op = &g_op[right_wait_cycle_for_op_code(cursor)];
    if (op)
    {
    	parse_types_code(struk, cursor, op);
    	if (is_arg_types_valid(cursor, op) && is_args_valid(cursor, struk, op))
    	    printf("EXECUTE ACTION\n");
    	else
    	 cursor->step += calc_step(cursor, op);
    	move_cursor(struk, cursor);
    }
    return (0);
}

// Ici on parcours tous nos process, on check voir si ils doivent mourrir,
// si oui on les tues, si non on check voir si ils peuvent jouer.
// Si ils peuvent ben ils jouent :D
int process_actions(t_main *struk, int cycles)
{
    t_process *tmp;
    t_process *prev;
    tmp = struk->agent;
    prev = NULL;

    while (tmp)
    {
      if (tmp->wait_cycles == 0)
          assign_opcode(struk, tmp);
      if((tmp->wait_cycles > 0))
          tmp->wait_cycles--;
      if (tmp->wait_cycles == 0)
          check_operation(struk, tmp);
      prev = tmp;
      tmp = tmp->next;
    }
    if (struk->die == 1)
        struk->die = 0;
    return (0);
}

// Ici on a le maitre du jeu, qui s'assure que les règles sont bien respecter
// et check tous les X tours que tous le monde a dis qu'ils étaient en vie.

void main_while(t_main *struk)
{
    while (struk->nbr_cursor > 0)
    {
        if (process_actions(struk, struk->cycles) == -1)
          leave("big fail in main while");
        if (struk->nbr_cycles == struk->inter_cycles || struk->nbr_cycles < 0)
              struk->inter_cycles = check_die_cycle(struk, struk->cycles);
        struk->inter_cycles++;
        struk->cycles++;
    }
}

int check_die_cycle(t_main *struk, int cycles)
{
    struk->checks_num++;
  	//printf("%d\n",struk->checks_num);
  	if (struk->checks_num == MAX_CHECKS && struk->lives_num >= NBR_LIVE)
  	{
  		struk->nbr_cycles -= CYCLE_DELTA;
  		printf("HELLO\n");
  		struk->checks_num = 0;
  	}
    exit(0);
  	//printf("%s\n", "reset_lives_nums");
  	struk->inter_cycles = 0;
    return (1);
}

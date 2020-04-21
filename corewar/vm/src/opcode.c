#include "../includes/corewar.h"

/*
** Cette fonction porte bien son nom, ce qu'elle fait en plus
** c'est qu'elle assigne aussi un temps d'attente en fonction
** de l'opération qu'elle doit éffectuer.
*/
int right_wait_cycle_for_op_code(t_process *cursor)
{
  int i;

  i = 0;
  while(i < 16)
  {
    if(g_op[i].code == cursor->opcodes)
      return (i);
    i++;
  }
  return(0);
}


void assign_opcode(t_main *struk, t_process *cursor)
{
    if (cursor->opcodes == -1) //|| struk->map->arena[cursor->position] != cursor->opcodes) // Attention a cette condition car on peut tomber plusieurs fois sur la meme instructions
    {
        if (struk->map->arena[cursor->position] >= 1 && struk->map->arena[cursor->position] <= 16)
        {
            cursor->opcodes = struk->map->arena[cursor->position];
            cursor->wait_cycles = g_op[right_wait_cycle_for_op_code(cursor)].cycles;
        }
        else
        {
            cursor->opcodes = -1;
            cursor->wait_cycles = 1;
        }
    }
}

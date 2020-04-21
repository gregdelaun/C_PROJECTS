#include "../includes/corewar.h"

void    print_cursor(t_main *struk, t_process *curs)
{
    int i = 0;
    printf("id___: %d __", curs->id);
    printf("carry: %d __", curs->carry);
    printf("posit: %d __", curs->position);
    printf("live_: %d __", curs->last_live);
    printf("wait_: %d __", curs->wait_cycles);
    printf("jump_: %d __", curs->jump);
    while(i <= REG_NUMBER)
    {
        printf("|regi[%02d]: %d|", i, curs->registeries[i]);
        if (i == 0 || i == REG_NUMBER || i == REG_NUMBER / 2)
            printf("\n");
        i++;
    }
        printf("\n");
}

void    print_map(t_main *struk)
{
    int i = 0;
    printf("ARENA\n[");
    while(i <= MEM_SIZE)
    {
        printf(" %02x ", struk->map->arena[i]);
        i++;
    }
    printf("]\n");
}

/*
**  Cette fonction transforme notre aire de jeux en mémoire circulaire.
*/
int circular_memory(int position, int movement, int memory_size)
{
    int result;

    result = position + movement;
    if (result >= memory_size)
        return (result % memory_size);
    return (result);
}

int check_position_to_start(t_main *struk, int id)
{
    int i;
    int start;

    i = 0;
    start = MEM_SIZE / struk->nbr_player;
    i = start * (id - 1);
    return (i);
}

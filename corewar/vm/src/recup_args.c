#include "../includes/corewar.h"

int	is_a_register(t_process *cursor, t_main *struk, int32_t step)
{
	int8_t reg_id;

	reg_id = struk->map->arena[cursor->position + step];
  if(reg_id >= 1 && reg_id <= REG_NUMBER)
    return (1);
  else
    return (0);
}

uint32_t	step_size(uint8_t arg_type, t_op *op)
{
	if (arg_type == T_REG)
		return (REG_LEN);
	else if (arg_type == T_DIR)
		return (op->t_dir_size);
	else if (arg_type == T_IND)
		return (IND_SIZE);
	return (0);
}

int			is_args_valid(t_process *cursor, t_main *struk, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (1 + (op->args_type_code ? 1 : 0));
	while (i < op->args_num)
	{
	  if ((cursor->args_type[i] == T_REG) && !is_a_register(cursor, struk, step))
	 	    return (0);
	 	step += step_size(cursor->args_type[i], op);
	 	i++;
	}
	return (1);
}

int32_t		calc_addr(int32_t addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}

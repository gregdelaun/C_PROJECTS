#include "../includes/corewar.h"

void	set_arg_type(int8_t arg_type, int8_t index, t_process *cursor)
{
  if(arg_type == 0x01)
	   cursor->args_type[index - 1] = T_REG;
  if(arg_type == 0x02)
   	 cursor->args_type[index - 1] = T_DIR;
  if(arg_type == 0x04)
     cursor->args_type[index - 1] = T_IND;
}

void		parse_types_code(t_main *struk, t_process *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_type_code)
	{
		args_types_code = struk->map->arena[cursor->position + 1];
		if (op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, cursor);
		if (op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, cursor);
		if (op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, cursor);
	}
	else
		cursor->args_type[0] = op->args_type[0];
 }

int		is_arg_types_valid(t_process *cursor, t_op *op)
{
	int32_t i;

	i = 0;
	while (i < op->args_num)
	{
		if (!(cursor->args_type[i] & op->args_type[i]))
			return (0);
		i++;
	}
	return (1);
}


uint32_t	calc_step(t_process *cursor, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = 0;
	step = step + 1;
  if (op->args_type_code)
    step = step + 1;
	while (i < g_op[cursor->opcodes - 1].args_num)
	{
		step += step_size(cursor->args_type[i], op);
		i++;
	}
	return (step);
}

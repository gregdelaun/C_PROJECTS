/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <tjuzen@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:38:01 by tjuzen            #+#    #+#             */
/*   Updated: 2020/03/03 17:57:14 by bsuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
#define COREWAR_H

#include "../libft/includes/libft.h"
#include <ncurses.h>
#include "op.h"
#include <time.h>

/*
** Buttons
*/

#define ESC 27
#define SPACE ' '
#define SPEED_UP_10 't'
#define SPEED_UP_100 'y'
#define SPEED_DOWN_10 'w'
#define SPEED_DOWN_100 'q'
#define SPEED_DEFAULT 'd'
#define CYCLE_TO_WAIT 50
#define DEFAULT_SPEED 50

typedef struct s_po t_process;

typedef struct s_lo
{
	char *name;
	int code_length;
	uint8_t *code;
	int ID;
	char *comment;
	int last_live;
} t_player;

typedef struct s_lut
{
	unsigned char arena[MEM_SIZE];
	int code_property[MEM_SIZE];
	int cursor_map[MEM_SIZE];
	WINDOW *warena;
	WINDOW *winfos;
	int maxlines;
	int maxcols;
	int is_running;
	int speed;
	int cursor_pos;
	int button;
} t_arena;

typedef struct s_ro
{
	int max_cycle;
	int nbr_live;
	int die;
} t_tab;

typedef struct s_po
{
	int id;
	int carry;
	int opcodes;
	int position;
	int last_live;
	uint8_t	args_type[3];
	int wait_cycles;
	int step;
	int jump;
	int registeries[REG_NUMBER];
	t_process *next;
} t_process;

typedef struct s_la
{
	int nbr_player;
	int visu;
	int order_player[MAX_PLAYERS][1];
	int nbr_cycles;
	t_player player[MAX_PLAYERS];
	t_arena *map;
	int die;
	int last_player;
	int max_cycle;
	t_process *agent;
	int cycles;
	int inter_cycles;
	int	checks_num;
	int lives_num;
	int nbr_cursor;
} t_main;


typedef struct	s_op
{
	char			*name;
	uint8_t		code;
	uint8_t		args_num;
	bool		args_type_code;
	uint8_t		args_type[3];
	bool		mod_carry;
	uint8_t		t_dir_size;
	uint32_t	cycles;
}								t_op;

typedef void (*action)(t_main *struk, t_process *cursor);

void init_vm(int argc, char **argv);
void check_params(int argc, char **argv);
int check_if_file(char **argv, int i);
t_main *check_arguments(int argc, char **argv, t_main *struk);
t_main *check_cycles(t_main *struk, char **argv, int i);
int check_previous_player_number(t_main *struk);
int open_files(int argc, char **argv, t_main *struk, int arg);
int check_if_zero(uint8_t *buf);
void problem_occured(char *problem);
void load_champ_to_arena(t_main *struk);

/*
** LEAVE.C
*/

void leave(char *msg);

/*
** INIT_MEMORY.C
*/

t_main init_memory(t_main struk, int num_player);

/*
** INIT_RULES.C
*/

void init_all_rules(t_main *struk);
void upload_rules_var(t_main *struk);
void refresh_cursor(t_main *struk, t_process *tmp, int cycles);
void init_cursor(t_main *struk, int i);
int circular_memory(int position, int movement, int size);

/*
** RULES_ROUND.C
*/

int rules_round(t_main *struk);

/*
** OPCODE.C
*/

void assign_opcode(t_main *struk, t_process *cursor);
int right_wait_cycle_for_op_code(t_process *cursor);
int8_t	get_byte(t_process *cursor, t_main *struk, int32_t step);
uint32_t	step_size(uint8_t arg_type, t_op *op);
int		is_arg_types_valid(t_process *cursor, t_op *op);
void		parse_types_code(t_main *struk, t_process *cursor, t_op *op);
void	set_arg_type(int8_t arg_type, int8_t index, t_process *cursor);
int check_operation(t_main *struk, t_process *cursor);
void	move_cursor(t_main *struk, t_process *cursor);
int32_t		calc_addr(int32_t addr);
int			is_args_valid(t_process *cursor, t_main *struk, t_op *op);
int	is_a_register(t_process *cursor, t_main *struk, int32_t step);
uint32_t	calc_step(t_process *cursor, t_op *op);

/*
** PARSING_TWO.C
*/
t_main *some_other_parsing(int fd, t_main *struk, int num_play);
void problem_occured(char *problem);
int check_if_zero(uint8_t *buf);
t_main *some_parsing_checks(int fd, t_main *struk, int num_play);
/*
** CHECK_RULES.C
*/

int check_operation(t_main *struk, t_process *cursor);
int check_die_cycle(t_main *struk, int cycles);
int check_kill(int cycles, t_process *tmp, t_main *struk);

/*
** TOOLS.C
*/

void print_map(t_main *struk);
int check_position_to_start(t_main *struk, int id);
int circular_memory(int position, int movement, int size);
void print_cursor(t_main *struk, t_process *curs);

/*
** VISU.C
*/

void start_ncurses(t_main *struk);
void print_arena(t_main *struk);
void write_colors(int fg, int bg, t_main *struk, int i, int j, int z);
void print_infos(t_main *struk);
void print_header(t_main *struk);
void end_ncurses(t_main *struk);
void init_ncurses(t_main *struk);
void unsetcolor(int fg, int bg, t_main *struk);
void setcolor(int fg, int bg, t_main *struk);
void init_colorpairs(void);
int colornum(int fg, int bg);
short curs_color(int fg);
void main_visu(t_main *struk);
void print_all(t_main *struk);

void one(t_main *struk, t_process *cursor);
void two(t_main *struk, t_process *cursor);
void three(t_main *struk, t_process *cursor);
void four(t_main *struk, t_process *cursor);
void five(t_main *struk, t_process *cursor);
void six(t_main *struk, t_process *cursor);
void seven(t_main *struk, t_process *cursor);
void eight(t_main *struk, t_process *cursor);
void nine(t_main *struk, t_process *cursor);
void ten(t_main *struk, t_process *cursor);
void eleven(t_main *struk, t_process *cursor);
void twelve(t_main *struk, t_process *cursor);
void thirteen(t_main *struk, t_process *cursor);
void fourteen(t_main *struk, t_process *cursor);
void fiveteen(t_main *struk, t_process *cursor);
void sixteen(t_main *struk, t_process *cursor);
void main_while(t_main *struk);


static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_type_code = false,
		.args_type = {T_DIR, 0, 0},
		.mod_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_type_code = true,
		.args_type = {T_DIR | T_IND, T_REG, 0},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 5,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_type_code = true,
		.args_type = {T_REG, T_REG | T_IND, 0},
		.mod_carry = false,
		.t_dir_size = 4,
		.cycles = 5,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG, T_REG, T_REG},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG, T_REG, T_REG},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_type_code = false,
		.args_type = {T_DIR, 0, 0},
		.mod_carry = false,
		.t_dir_size = 2,
		.cycles = 20,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.mod_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.mod_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_type_code = false,
		.args_type = {T_DIR, 0, 0},
		.mod_carry = false,
		.t_dir_size = 2,
		.cycles = 800,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_type_code = true,
		.args_type = {T_DIR | T_IND, T_REG, 0},
		.mod_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_type_code = true,
		.args_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.mod_carry = true,
		.t_dir_size = 2,
		.cycles = 50,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_type_code = false,
		.args_type = {T_DIR, 0, 0},
		.mod_carry = false,
		.t_dir_size = 2,
		.cycles = 1000,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_type_code = true,
		.args_type = {T_REG, 0, 0},
		.mod_carry = false,
		.t_dir_size = 4,
		.cycles = 2,
	}
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:47 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/03 11:12:43 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "../minilibx_macos/mlx.h"
# include "./Libft/includes/libft.h"
# include "../../Libft/get_next_line/includes/get_next_line.h"
# include "../../Libft/ft_printf/includes/ft_printf.h"

typedef struct		s_values
{
	int				x;
	int				y;
	int				tx;
	int				ty;
	int				rep_pos;
	int				rep;
	int				scale;
}					t_values;

typedef struct		s_input
{
	char			**token;
	char			**map;
}					t_input;

typedef struct		s_window
{
	int				col_p1;
	int				col_p2;
	int				bg1;
	int				bg2;
	int				bg3;
	int				pause;
	char			*title;
	char			*player1;
	char			*player2;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_window;

typedef struct		s_replay
{
	int				rep_pos;
	char			*p1_score;
	char			*p2_score;
	char			**map;
	char			**token;
	struct s_replay	*next;
}					t_replay;

typedef struct		s_all
{
	int				p1;
	int				p2;
	int				gnl;
	t_values		*val;
	t_input			*input;
	t_window		*win;
	t_replay		*replay;
	t_replay		**rep_arr;
}					t_all;

/*
** -Input reading-organizing functions-
*/
char				*make_title(char *player1, char *player2);
int					select_scale(int x, int y);
char				*init_player_name(char *line);
void				get_map_size(char *line, int *x, int *y);
char				**new_map_piece(int x, int y);
int					color_select(char *str);
int					map_fillers(char *line, t_all *all, int i);
t_all				*malloc_lists(int argc, char **argv);
t_all				*init_gnl(t_all *all);
t_window			*init_window(t_all *all);
int					loop_gnl(void *param);
char				**make_opti_token(char **input, char **new_token);
void				get_token_size(char **map, int *x, int *y);

/*
** -Replay functions-
*/
t_replay			**new_replay_array(int max);
t_replay			*add_replay(t_all *all, int rep_pos);

/*
** -Keyboard
*/
int					move_forward(void *param);
int					key_press(int keycode, void *param);

/*
** -UI functions-
*/
void				game_loop(t_all *all);
void				draw_score(t_all *all, int start, int end, int color);
void				fill_score(t_all *all);
void				print_score_ui(t_all *all, int x, int scale);
void				update_print_score(t_all *all, int j);
void				print_start_score(t_all *all);
void				print_playernames(t_all *all);
void				print_strip(t_all *all);
void				print_background_2(t_all *all);
void				draw_line_hor(t_all *all, int start, int end, int i);
void				draw_line_ver(t_all *all, int start, int end, int i);
void				print_grid(t_all *all, int x, int y, int scale);
void				print_piece_ui(t_all *all, int x, int scale);
void				print_background(t_all *all);
void				print_lines(t_all *all);
void				print_lines_5(t_all *all, int temp);
void				fill_box(int x, int y, int color, t_all *all);
void				latest_played(int x, int y, int color, t_all *all);
void				draw_start(t_all *all);
void				color_box(t_all *all, int x, int y);
void				draw_map(t_all *all, int j);
void				fill_box_token(int x, int y, int color, t_all *all);
void				clear_box_token(int x, int y, t_all *all);
void				clear_prev_token(t_all *all, int j);
void				draw_token(t_all *all, int j);
void				draw_start_token(t_all *all);
int					windowclose(void *all);
int					reset_ui(t_all *all);

/*
**	-Free functions-
*/
void				free_window(t_window **w);
void				free_replay_arr(t_replay ***arr);
void				free_replay(t_replay **list);
void				free_val(t_values **val);
void				free_input(t_input **input);
t_all				*free_all(t_all *all);
void				program_quit(t_all *all);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:33:28 by quroba            #+#    #+#             */
/*   Updated: 2019/04/26 16:50:20 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int					g_nbr_tetrimonis;

typedef struct		s_lst
{
	char			**tab;
	int				x;
	int				y;
	char			letter;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_int
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int x;
	int y;
}					t_int;

int					read_file(char **buf);
char				*get_tetri(char *buff, int fd);
int					check_error(char *temp, int c, int b);
int					check_error2(char *temp, int i);
void				fre(char *temp, int j, int c);
int					count_hashtag(char *buf);
int					get_nbr_tetromonis(char *buff);
char				**put_in_tab(char *buf);
char				**put_in_tab2(char **tab, char *buff);
int					check_valid_tetri(char **tab);
int					check(int i, int j, char **tab);
t_lst				*put_tab_in_list(char **tab);
t_lst				*create_new_element(char **tab);
void				free_tab2(char **tab);
int					move_tab(t_lst *list);
int					time_move_left(char **tab);
char				**move_left(int times, char **tab);
int					time_move_up(char **tab);
char				**move_up(int times, char **tab);
int					resolve(t_lst *list);
char				**create_res_tab(int square_min);
char				**create_res_tab2(char **tab, int square_min);
t_lst				*init_list(t_lst *list);
int					backtracking(t_lst *list, int square, char **res);
int					test_pos(t_lst *list, char **res, int square);
char				**put_letter(t_lst *list, char **res);
char				**ft_delete(t_lst *list, char **res);
void				print(char **res);
t_lst				*free_list(t_lst *list);

#endif

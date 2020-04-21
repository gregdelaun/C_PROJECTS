# ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 1500
# define MAX_SIZE_FD 144


typedef struct s_lt
{
    char **tab;
    char **tok;
    char **tok2;
    char **res;
    int **heat;
    char  *mapjoin;
    char myplayer_id;
    char nmi_id;
    int y_board;
    int x_board;
    int y_token;
    int x_token;
    int savedfirst_j;
    int savedfirst_i;
    int saved_j;
    int saved_i;
    int retj;
    int reti;
    int final_x;
    int final_y;
    int score;
    int save;
    int save2;
    int w;
    int i;
    int j;
    int p;
    int a;
    int b;
    int c;
    int k;
    int nbr_two;
    int save_x;
    int save_y;
    int first_x;
    int first_y;
    int count_one;
    int bas;
    int haut;
    int gauche;
    int droite;
    int gauchesave;
    int hautsave;
    int good;
}               t_lt;

typedef struct r_lt
{
    int final_x;
    int final_y;
    int score;
    int ok;
    int on;
    int compteur;
    int plushaut;
    int plusgauche;
}              p_lt;

typedef struct k_lt
{
    int x;
    int y;
    float dist;
}               q_lt;

typedef struct o_lt
{
    int x_x;
    int y_x;
}              z_lt;

typedef struct  s_gnl
{
    char        *buf;
    int         count;
    int         i;
    int         nl;
    int         fd;
}               t_gnl;

int	ft_get_next_line(const int fd, char **line);
t_lt create_heat_map(t_lt arg);
t_lt init_the_heat2(t_lt arg, int x , int y);
t_lt init_the_heat(t_lt arg);
t_lt put_numbers_in_heat_two(t_lt arg, int i, int x, int y);
t_lt put_numbers_in_heat(t_lt arg);
t_lt check_format_board(t_lt args, char *line);
t_lt put_numbers_in_tab_for_big_x(t_lt args);
t_lt put_numbers_in_tab(t_lt args);
int check_token(t_lt *args, char *line);
char **copy_two_d_array(t_lt args);
int several_lenght_checks(t_lt *args, char *line, int ret);
int check_numbers_of_two(t_lt args);
p_lt fill_in_or_not_two(int y, int x, t_lt args, p_lt *fuck);
int several_lenght_checks_two(t_lt *args, char *line ,int ret);
void free_tabs(char **tab);
void print_result(p_lt fuck);
int check_colom(t_lt args, int j);
int check_colom_two(t_lt args, int j);
t_lt do_smaller_token(t_lt args);
t_lt do_new_token(t_lt args);
t_lt init_variab(t_lt args);
q_lt initialise_variables(t_lt *args, p_lt *fuck, q_lt coor[]);
void init_list(t_lt *args);
t_lt init_varaibles(t_lt args, int x, int y);
char** create_tab(char **res, int save, int save2);
t_lt init_varaibles_two(t_lt args, int x, int y);
void init_list_two(t_lt *args);
void continue_recusrive(t_lt args, int k, p_lt *fuck);
static p_lt check_valid_position(t_lt args, q_lt *coor, p_lt fuck);
int check_next_door(t_lt args, int i, int j);
int go_algo(t_lt args);
p_lt check_res_board(char **res, t_lt args, int x, int y, p_lt *fuck);
void free_two_day_tab(char **res);
int check_colom(t_lt args, int j);
int check_colom_two(t_lt args, int j);
t_lt do_smaller_token_two(t_lt args, int tmp2);
void init_list_two(t_lt *args);


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#endif

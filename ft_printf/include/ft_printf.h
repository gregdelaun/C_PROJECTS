/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:55:18 by grde-lau          #+#    #+#             */
/*   Updated: 2019/06/03 15:59:44 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../Libft/libft.h"
# include <limits.h>

typedef struct		s_lt
{
	va_list			var;
	char			*temp;
	char			*dis;
	intmax_t		dig;
	unsigned int	dig2;
	char			*str;
	char			ch;
	const char		*s;
	int				poz;
	int				hash;
	int				plus;
	int				lol;
	int				moins;
	int				zero;
	int				space;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				bigl;
	int				width;
	int				widthnm;
	int				precnm;
	int				prec;
	int				still;
	char			conv;
	char			c;
	int				t;
	int				g;
	int				i;
	int				x;
	int				y;
	int				z;
	int				j;
	int				modz;
	int				minus;
}					t_lt;

typedef struct		s_fonct
{
	t_lt			(*ptr_fonc)(t_lt);
	char			key;
}					t_fct;

int					g_rvalue;

void				ft_puts(const char *s);
int					check_next(char *temp, int i);
int					go_to_conversion(char *temp, int i);
t_lt				initialise_list(t_lt args);
t_lt				modif_longeur(t_lt *args, char *conv, int start);
int					is_not_specific1(char c);
int					is_a_conversion(char c);
int					ft_activate1_list(char *conv, int start, t_lt *args);
int					go_to_conversion2(char *temp, int i);
void				print_test(t_lt args);
t_lt				work_on_it_d(t_lt args);
void				do_plus(t_lt *args);
void				do_zero(t_lt *args);
int					count_length_digit(t_lt args);
void				do_width(t_lt *args);
t_lt				do_minus(t_lt *args);
void				do_space(t_lt *args);
int					cout_digit(t_lt args);
t_lt				ft_conversion(char *conv, int atc, int start, t_lt args);
int					ft_printf(const char *restrict format, ...);
int					check_value_width(t_lt args);
void				open_specif(t_lt *args);
void				other_stuffs(t_lt *args);
t_lt				work_on_it_o(t_lt args);
t_lt				work_on_it_c(t_lt args);
t_lt				work_on_it_s(t_lt args);
t_lt				work_on_it_u(t_lt args);
void				open_specif_u(t_lt *args);
int					ft_len_base(intmax_t value, int base);
char				*ft_toa_base_(intmax_t value, int base, t_lt args);
t_lt				work_on_it_big_x(t_lt args);
char				*ft_toa_base_2(intmax_t value, int base);
void				ft_check_o(t_lt args);
int					ft_check_o_x_x(t_lt args);
int					do_normal_s(t_lt args);
void				ft_putstr_l(const char *str, int l);
t_lt				work_on_it_pourcent(t_lt args);
t_lt				ft_dooo_minus(t_lt args);
t_lt				do_minus_for_pourcent(t_lt args);
int					check_valid_conversion(char *temp, int i);
int					go_till_next_for_print(char *temp, int i);
int					is_a_specifier(char c);
char				*return_max_string(t_lt args);
void				ft_putnbr_lib(intmax_t n, t_lt args);
int					check_minusone_value(t_lt args);
t_lt				do_minus_for_o(t_lt *args);
void				do_zero_for_o(t_lt *args);
void				do_width_for_o(t_lt *args);
int					check_value_width_for_o(t_lt args);
void				do_zero_for_x(t_lt *args);
void				do_width_for_x(t_lt *args);
int					check_value_width_for_x(t_lt args);
t_lt				do_minus_for_x(t_lt *args);
t_lt				work_on_it_pointeurs(t_lt args);
t_lt				do_minus_p(t_lt args);
void				do_width_p(t_lt args);
t_lt				work_on_it_float(t_lt args);
void				ft_printf_spaces(int i);
void				ft_printf_zero(int j);
int					check_power(int val, int pow);
char				*place_decimal(int i, char *ret, uintmax_t dec);
int					check_frac(uintmax_t frac);
char				*return_string_spec(intmax_t value);

#endif

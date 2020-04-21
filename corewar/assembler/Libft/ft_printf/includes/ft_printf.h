/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:27:33 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/02 12:12:22 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../../Libft/includes/libft.h"
# include <limits.h>
# define C_RED "\033[0;31m"
# define C_BLUE "\033[0;34m"
# define C_GREEN "\033[0;32m"
# define C_PURPLE "\033[0;35m"
# define C_PINK "\033[1;35m"
# define C_CYAN "\033[0;36m"
# define C_YELLOW "\033[0;33m"
# define C_RESET "\033[0m"

typedef struct	s_ft
{
	va_list	vl;
	char	*buff;
	char	*temp;
	char	*temp2;
	int		c0;
	int		width;
	int		after;
	char	align;
	char	pad;
	char	f;
	int		hash;
	int		space;
	int		sign;
	int		dot;
	int		prec;
	int		fd;
	int		h;
	int		l;
	int		z;
	int		j;
}				t_ft;

int				ft_printf(const char *format, ...);
void			ft_char_out(int c, t_ft *input, int *j);
void			ft_str_out(t_ft *input, int *j);
void			ft_dec_out(t_ft *input, int *j);
void			ft_f_out(t_ft *input, int *j);
void			ft_u_out(t_ft *input, int *j);
void			ft_o_out(t_ft *input, int *j);
void			ft_hex_out(t_ft *input, int *j);
void			ft_p_out(t_ft *input, int *j);
void			ft_b_out(t_ft *input, int *j);
void			ft_n(t_ft *input, int *j);
void			ft_percentage(t_ft *input, int *j);
void			ft_g_out(t_ft *input, int *j);
void			ft_e_out(t_ft *input, int *j);
void			ft_fd(t_ft *input);
t_ft			*initstruct(t_ft *input);
t_ft			*inreset(t_ft *input);
void			inprep(t_ft *input, const char *format, int *i);
void			widthconv_c(t_ft *input, int *j, int c);
void			widthconv_str(t_ft *input, int *j);
void			put_prec_dioux(t_ft *input);
void			space_sign_placer(t_ft *input);
void			left_align(t_ft *input, int i);
void			right_align(t_ft *input, int i);
void			no_align(t_ft *input, int *j);
void			sign_replacer(t_ft *input);
void			n_out_l(long *out, int *j);
void			n_out_ll(long long *out, int *j);
void			n_out_h(short *out, int *j);
void			n_out_hh(signed char *out, int *j);
void			n_out_z(size_t *out, int *j);

#endif

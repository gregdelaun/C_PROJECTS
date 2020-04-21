/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:17:58 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/07 15:44:01 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** char
*/
char			**ft_chararrclr(char **str);
char			**ft_chararrclr_old(char **ap, int length);
char			*ft_charcat(char *dest, const char src);
void			ft_charswap(char *a, char *b);
int				ft_chartoupper(int c);
void			pt_charput_c_rot(char **str, char c, int pos, int rot);
void			ft_chararrprint(char **arr);
/*
** int
*/
char			*pt_intoctal(unsigned int input, char *temp);
int				ft_conn_amount(char **matrix, int line);
char			*pt_intoctal_z(size_t input, char *temp);
char			*pt_intoctal_ll(unsigned long long int input, char *temp);
char			*pt_intoctal_l(unsigned long int input, char *temp);
char			*pt_intoctal_j(uintmax_t input, char *temp);
char			*pt_intoctal_hh(unsigned char input, char *temp);
char			*pt_intoctal_h(unsigned short int input, char *temp);
int				ft_inttopower(int n, int power);
int				ft_intmakepos(int in);
void			ft_intarrprint(int **arr, int max_x, int max_y);
void			ft_intarrclr(int **ap, int y);
int				*ft_intarr(int size, int start_value);
int				*ft_setintarr(int size, int set_value, int *arr);
int				*ft_copyintarr(int size, int *new, int *old);
char			*pt_inttohexastr_h(unsigned short deci, int i, char *h,\
				char *temp);
char			*pt_inttohexastr_hh(unsigned char deci, int i, char *h,\
				char *temp);
char			*pt_inttohexastr_j(intmax_t d, int i, char *h, char *t);
char			*pt_inttohexastr_l(unsigned long d, int i, char *h, char *t);
char			*pt_inttohexastr_ll(unsigned long long d, int i, char *h,\
				char *t);
char			*pt_inttohexastr_z(size_t d, int i, char *h, char *t);
char			*pt_inttohexastr(unsigned int deci, int i, char *hexa,\
				char *temp);
/*
** is
*/
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_iseven(int n);
int				ft_ishexa(char *str);
int				ft_isprint(int c);
int				ft_isprintfflag(int c);
int				ft_iswhitespace(int c);
int				ft_iswhitespace2(int c);
/*
** lst
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstrev(t_list **alst);
/*
** mem
*/
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			ft_memdel(void **ap);
void			ft_memdell(void *ap);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
/*
** other
*/
int				ft_atoi(const char *str);
unsigned int	ft_atoi_uint(const char *str);
int				ft_natoi(const char *str, int len);
int				ft_binlen_u(unsigned long int n);
int				ft_binlen(long n);
void			ft_bzero(void *str, size_t n);
int				ft_divlen_ul(unsigned long long int n, int divn);
int				ft_divlen(long long int n, int divn);
int				ft_hexaconverter(char *str);
int				ft_hexaconverter_old(char *str);
char			ft_hexavalue(unsigned long int rem, char *hexa, int l);
char			*ft_itoa(int n);
char			*ft_reversebin(char *bin);
char			*ft_scinot_l(long double n, int after, char *temp, char *temp2);
char			*ft_scinot(double n, int after, char *temp, char *temp2);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*pt_bintohex(char *hexa, char *temp);
char			*pt_dectobin_l(unsigned long int n, char *temp);
char			*pt_dectobin(int n, char *temp);
char			*pt_ftoa_l(long double n, long after, char *tempi, char *tempf);
char			*pt_ftoa(double n, int after, char *tempi, char *tempf);
char			*pt_itoa_h(short n, char *temp);
char			*pt_itoa_hh(signed char n, char *temp);
char			*pt_itoa_j(intmax_t n, char *temp);
char			*pt_itoa_l(long n, char *temp);
char			*pt_itoa_ll(long long n, char *temp);
char			*pt_itoa_uint_h(unsigned short n, char *temp);
char			*pt_itoa_uint_hh(unsigned char n, char *temp);
char			*pt_itoa_uint_j(uintmax_t n, char *temp);
char			*pt_itoa_uint_l(unsigned long n, char *temp);
char			*pt_itoa_uint_ll(unsigned long long int n, char *temp);
char			*pt_itoa_uint_z(size_t n, char *temp);
char			*pt_itoa_uint(unsigned int n, char *temp);
char			*pt_itoa_z(size_t n, char *temp);
char			*pt_itoa(int n, char *temp);
char			*pt_pointeraddress(void *in, char *temp, char *temp2);
char			**ft_arrclr(char **arr);
int				ft_n0(char c);
int				ft_random(int max);
int				ft_toupper(int c);
int				ft_find_c(char *line, char c);
/*
** put
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd_c0(char const *s, int fd, int c0);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
/*
** str
*/
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcatnl(char *dest, const char *src);
char			*ft_strchr(const char *str, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strdel_neg(char **as);
void			ft_strdel(char **as);
void			ft_strdell(char *as);
char			*ft_strdup(const char *src);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinn(char *s1, char const *s2);
char			*ft_strjoinspace(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen_c(const char *str, int c);
size_t			ft_strlen_c0(const char *str, int c0);
size_t			ft_strlen(const char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat_c0(char *dest, const char *src, size_t n, int c);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *hay, const char *needle, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strrevcpy(char *dest, const char *src);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtoupper(char *str);
char			*ft_strtrim(char const *s);
char			*pt_strmove(char *str, char *str2, int n);
void			pt_strrot(char **str, int n);
char			*ft_strccpy(char *dest, const char *src, int c);
size_t			ft_strclen(char *str, int c);
char			*ft_strnewncpy(int len, char *src);

#endif

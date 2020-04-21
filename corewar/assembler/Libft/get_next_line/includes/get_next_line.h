/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 10:00:29 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/17 17:02:19 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# include "../../Libft/includes/libft.h"
# include <limits.h>

int		get_next_line(const int fd, char **line);
int		get_next_line_old(const int fd, char **line);

#endif

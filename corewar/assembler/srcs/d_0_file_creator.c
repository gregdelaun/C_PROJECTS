/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_0_file_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:25 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:42:26 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	>>= 8 ==> shift bits to the right by 8 bits
**	This is equal to dividing by 255, the max value of 1 byte
*/

static void	write_magic(int file, int magic, int len)
{
	int				j;
	unsigned char	c[len];

	j = len;
	while (j--)
	{
		c[j] = (unsigned char)magic;
		magic >>= 8;
	}
	j = -1;
	while (++j < len)
		write(file, &c[j], 1);
}

/*
**	Write header into the file
*/

static void	write_header(int file, t_all *all)
{
	int i;

	i = -1;
	write_magic(file, COREWAR_EXEC_MAGIC, 4);
	while (all->h.prog_name[++i])
		ft_putchar_fd(all->h.prog_name[i], file);
	while (++i < PROG_NAME_LENGTH + 5)
		ft_putchar_fd(0, file);
	write_magic(file, all->len, 4);
	i = -1;
	while (all->h.comment[++i])
		ft_putchar_fd(all->h.comment[i], file);
	while (++i < COMMENT_LENGTH + 5)
		ft_putchar_fd(0, file);
}

/*
**	Creates file using the created filename from the .s file
**	O_CREAT ==> creates file if non-existant
**	O_TRUNC ==> makes sure file is empty
**	O_RDWR ==> allows us to read and write in file
**	0644 ==> chmod rights
*/

void		create_file(t_all *all)
{
	int	file;

	if (all->l == NULL)
		error_message("File contains no instructions\n", all, NULL);
	if ((file = open(all->file, O_CREAT | O_TRUNC | O_RDWR, 0644)) < 0)
	{
		close(file);
		error_message("Error while creating .cor file\n", all, NULL);
	}
	write_header(file, all);
	write(file, all->result, all->len);
	ft_putstr("Writing output program to ");
	ft_putendl(all->file);
	close(file);
}

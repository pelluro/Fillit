/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:35:02 by mipham            #+#    #+#             */
/*   Updated: 2017/12/01 19:50:28 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../src/libft/libft.h"

typedef struct s_tetri	t_tetri;
struct	s_tetri
{
	char	name;
	int		*x[4];
	int		*y[4];
	t_tetri	*next;

};

t_tetri	*read_map(char *s, char name);
t_tetri	*arrange_up_left(t_tetri *b);
t_tetri	*ft_readfile(char *filename);
t_tetri	*ft_read(int fd, int a);
t_tetri	*malloc_struct(t_tetri *block);

char	*new_grid(int size);
char	*fillgrid(char *grid, t_tetri *elem, int x, int y);
char	*tryputgrid(char *grid, t_tetri *elem, int x, int y);
char	*makegrid(t_tetri *lst);
char	*ft_read_test(int fd);
char		*ft_readfile_last(char *filename);

int		pos_test(char *grid, t_tetri *block, int x, int y);
int		get_grid_size_min(int nb_tetri);
int		ft_count(t_tetri *firstelem);
int		ft_check(char *s);
int		check_line(char *s);
int		check_connection(char *str);
int		check_map(char *s);
int		get_grid_size(char *grid);
int   ft_check_last(char *s);
void	write_grid(char *grid, t_tetri *block, int x, int y);

#endif

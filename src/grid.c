/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:50:05 by mipham            #+#    #+#             */
/*   Updated: 2017/12/01 17:03:33 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			pos_test(char *grid, t_tetri *block, int x, int y)
{
	int i;
	int size;
	int x_pos;
	int y_pos;

	i = 0;
	size = get_grid_size(grid);
	while (i < 4)
	{
		x_pos = x + *(block->x[i]);
		y_pos = y + *(block->y[i]);
		if ((y_pos * (size + 1) + x_pos >= (size + 1) * (size) + 1) ||
				grid[y_pos * (size + 1) + x_pos] != '.' ||
				x_pos >= size || y_pos >= size)
			return (0);
		i++;
	}
	return (1);
}

void		write_grid(char *grid, t_tetri *block, int x, int y)
{
	int i;
	int size;
	int x_pos;
	int y_pos;

	i = 0;
	size = get_grid_size(grid);
	while (i < 4)
	{
		x_pos = x + *(block->x[i]);
		y_pos = y + *(block->y[i]);
		grid[y_pos * (size + 1) + x_pos] = block->name;
		i++;
	}
}

char		*new_grid(int size)
{
	char	*grid;
	int		s;
	int		i;

	i = 0;
	s = (size + 1) * size + 1;
	if (!(grid = (char *)malloc(sizeof(char) * s)))
		return (NULL);
	while (i < s - 1)
	{
		if (i % (size + 1) == size)
			grid[i] = '\n';
		else
			grid[i] = '.';
		i++;
	}
	grid[i] = '\0';
	return (grid);
}

int			get_grid_size(char *grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		if (grid[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int			get_grid_size_min(int nb_tetri)
{
	int size;
	int nb;

	nb = nb_tetri * 4;
	while (ft_sqrt(nb) == 0)
		nb++;
	size = ft_sqrt(nb);
	return (size);
}

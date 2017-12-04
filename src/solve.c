/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:39:26 by mipham            #+#    #+#             */
/*   Updated: 2017/12/01 19:36:48 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri		*malloc_struct(t_tetri *block)
{
	int count;

	if (!(block = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	count = 0;
	while (count < 4)
	{
		block->x[count] = (int*)malloc(sizeof(int));
		block->y[count] = (int*)malloc(sizeof(int));
		count++;
	}
	return (block);
}

char		*makegrid(t_tetri *lst)
{
	int		size;
	char	*r;

	size = get_grid_size_min(ft_count(lst));
	r = NULL;
	if (!lst)
		return (0);
	while (r == NULL)
		r = fillgrid(new_grid(size++), lst, 0, 0);
	return (r);
}

char		*fillgrid(char *grid, t_tetri *elem, int x, int y)
{
	char	*griddup;
	char	*griddup2;
	t_tetri	*elem2;
	int		s;

	griddup = tryputgrid(grid, elem, x, y);
	if (griddup)
	{
		elem2 = elem->next;
		if (!elem2)
			return (griddup);
		griddup2 = fillgrid(griddup, elem2, 0, 0);
		if (griddup2)
			return (griddup2);
	}
	s = get_grid_size(grid);
	if (x < s - 1)
		return (fillgrid(grid, elem, x + 1, y));
	if (y < s - 1)
		return (fillgrid(grid, elem, 0, y + 1));
	return (NULL);
}

char		*tryputgrid(char *grid, t_tetri *elem, int x, int y)
{
	char	*grid2;

	if ((pos_test(grid, elem, x, y)) == 0)
		return (NULL);
	if (!(grid2 = ft_strdup(grid)))
		return (NULL);
	write_grid(grid2, elem, x, y);
	return (grid2);
}

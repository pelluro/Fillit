/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:26 by mipham            #+#    #+#             */
/*   Updated: 2017/12/01 16:50:55 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri		*read_map(char *s, char name)
{
	int		i;
	int		count;
	t_tetri	*block;

	i = 0;
	count = 0;
	block = NULL;
	if (!ft_check(s))
		return (0);
	if (!(block = malloc_struct(block)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == '#')
		{
			*(block->x[count]) = i % 5;
			*(block->y[count]) = i / 5;
			count++;
		}
		i++;
	}
	block->name = name;
	return (block);
}

t_tetri		*arrange_up_left(t_tetri *b)
{
	int i;
	int y;
	int x_min;

	i = 0;
	x_min = *(b->x[0]);
	y = *(b->y[0]);
	while (i < 4)
	{
		*(b->y[i]) = *(b->y[i]) - y;
		if (*(b->x[i]) < x_min)
			x_min = *(b->x[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		*(b->x[i]) = *(b->x[i]) - x_min;
		i++;
	}
	return (b);
}

t_tetri		*ft_readfile(char *filename)
{
	int		fd;
	t_tetri	*firstelem;

	if (!(firstelem = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	firstelem = ft_read(fd, 0);
	close(fd);
	return (firstelem);
}

t_tetri		*ft_read(int fd, int ret)
{
	char		buff[22];
	char		name;
	t_tetri		*oldelem;
	t_tetri		*firstelem;
	t_tetri		*blockread;

	name = 'A';
	oldelem = NULL;
	while ((ret = read(fd, buff, 21)))
	{
		buff[ret] = '\0';
		if (!(blockread = read_map(buff, name++)))
			return (NULL);
		blockread = arrange_up_left(blockread);
		if (oldelem)
		{
			oldelem->next = blockread;
			oldelem = blockread;
		}
		else
		{
			oldelem = blockread;
			firstelem = blockread;
		}
	}
	return (firstelem);
}

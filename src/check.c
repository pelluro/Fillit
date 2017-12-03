/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:09:01 by mipham            #+#    #+#             */
/*   Updated: 2017/12/01 17:03:40 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_map(char *s)
{
	int i;
	int diese;
	int point;
	int end;

	i = 0;
	diese = 0;
	point = 0;
	end = 0;
	while (i < 20)
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			diese++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			end++;
		i++;
	}
	if (diese != 4 || point != 12 || end != 4)
		return (0);
	return (1);
}

int		check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return ((block == 6 || block == 8) ? 1 : 0);
}

int		check_line(char *s)
{
	int i;

	i = 0;
	while (i < 21)
	{
		if (i % 5 == 4 && s[i] != '\n')
			return (0);
		i++;
	}
	if (s[20] == '\0')
		return (2);
	if (s[20] != '\n')
		return (0);
	return (1);
}

int		ft_check(char *s)
{
	int l;

	l = check_line(s);
	if (l == 0 || check_connection(s) == 0 || check_map(s) == 0)
		return (0);
	return (l);
}

int		ft_count(t_tetri *firstelem)
{
	int		nb;
	t_tetri	*tmp;

	nb = 0;
	tmp = firstelem;
	while (tmp != NULL)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

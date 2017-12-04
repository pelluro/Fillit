/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:12:45 by mipham            #+#    #+#             */
/*   Updated: 2017/12/04 15:58:31 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_readfile_last(char *filename)
{
	int		fd;
	char	*str;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	str = ft_strdup(ft_read_test(fd));
	if (str == NULL)
		return (NULL);
	close(fd);
	return (str);
}

char	*ft_read_test(int fd)
{
	char	buff[600];
	char	*str;
	int		read_nb;

	read_nb = 0;
	read_nb = read(fd, buff, 599);
	buff[read_nb] = '\0';
	if (!(str = ft_strndup(buff, read_nb)))
		return (NULL);
	return (str);
}

int		ft_check_last(char *s)
{
	int size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	if (size == 0)
		return (0);
	if (s[size - 1] == '\n' && s[size - 2] == '\n')
		return (0);
	return (1);
}

int		ft_error(void)
{
	ft_putendl("error");
	return (0);
}

int		main(int argc, char **argv)
{
	char		*res;
	char		*s;
	t_tetri		*lst;

	if (argc < 2)
		ft_putendl("no argument");
	else
	{
		s = ft_readfile_last(argv[1]);
		if (ft_check_last(s) == 0)
			return (ft_error());
		lst = ft_readfile(argv[1]);
		if (!lst)
			return (ft_error());
		res = makegrid(lst);
		ft_putstr(res);
		if (res == NULL)
			return (ft_error());
	}
	return (0);
}

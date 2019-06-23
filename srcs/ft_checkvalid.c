/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:31 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/30 16:40:08 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_skipcolor(char *line, int i)
{
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	if (line[++i] != 'x')
		return (-1);
	i++;
	while (line[i] != ' ')
	{
		if ((line[i] >= '0' && line[i] <= '9')
		|| (line[i] >= 'a' && line[i] <= 'z') ||
		(line[i] >= 'A' && line[i] <= 'Z'))
			i++;
		else
			return (-1);
	}
	return (i);
}

static int		ft_checkstr(char *line)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			if ((i = ft_skipcolor(line, ++i)) == -1)
				return (0);
		if ((line[i] >= '0' && line[i] <= '9') ||
		(line[i] == ' ') || (line[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

int				ft_not(int count)
{
	count = 0;
	ft_putendl("not a valid map");
	return (0);
}

static int		ft_checkmap(int fd, t_map *fdf)
{
	char	buf[1];
	char	*line;
	int		count;

	line = 0;
	count = 0;
	if ((read(fd, buf, 0)) == -1)
	{
		ft_putendl("file reading error");
		return (0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (!(ft_checkstr(line)))
			return (ft_not(count));
		count++;
		free(line);
	}
	if (count == 1)
		return (ft_not(count));
	fdf->ly = count;
	return (1);
}

int				ft_checkvalid(int ac, char **av, t_map *fdf)
{
	int		fd;

	if (ac != 2)
	{
		if (ac == 1)
			ft_putendl("usage source file");
		else
			ft_putendl("too many arguments");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("file reading error");
		return (0);
	}
	if (!(ft_checkmap(fd, fdf)))
		return (0);
	return (1);
}

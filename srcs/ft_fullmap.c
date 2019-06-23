/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:53:13 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 18:14:52 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_countdigit(char *line)
{
	int			count;
	size_t		i;
	static int	temp = -1;

	count = 0;
	i = 0;
	while (i < ft_strlen(line))
	{
		if ((i == 0 && ft_isdigit((int)line[i])) || line[i] == '-')
			count++;
		else if ((ft_isdigit((int)line[i]) && line[i - 1] == ' ') ||
		(i == 0 && line[i] == '-'))
			count++;
		i++;
	}
	if (temp != -1)
		if (temp != count)
		{
			ft_putendl("Not a valid map");
			return (0);
		}
	temp = count;
	return (count);
}

static	int		ft_check(char *line, int j)
{
	if ((ft_isdigit(line[j]) && line[j - 1] == ' ') || (line[j] == '-') ||
		(j == 0 && ft_isdigit((int)line[j])))
		return (1);
	return (0);
}

static int		*ft_full(int *maps, char *line, t_map *fdf, int c)
{
	int			i;
	size_t		j;

	i = -1;
	j = -1;
	if ((fdf->lx = ft_countdigit(line)) == 0)
		return (0);
	if (!(maps = (int*)ft_memalloc(sizeof(int) * fdf->lx)))
		return (0);
	while (++j < ft_strlen(line))
	{
		if (line[j] == ',')
			if (!(ft_get_color(fdf, &line[j + 1], c, i)))
				return (0);
		if (ft_check(line, j))
		{
			if (line[j] == '0')
				maps[++i] = 0;
			else if (ft_isdigit(line[j]))
				maps[++i] = ft_atoi(&line[j]);
			else if (line[j] == '-')
				maps[++i] = ft_atoi(&line[j]);
		}
	}
	return (maps);
}

int				ft_fullmap(t_map *fdf, char *av)
{
	int		fd;
	int		i;
	char	*line;
	int		res;

	i = -1;
	res = 0;
	line = 0;
	fd = open(av, O_RDONLY);
	if (!(fdf->map = (int**)ft_memalloc(sizeof(int*) * fdf->ly)))
		return (0);
	while (++i < fdf->ly)
	{
		if ((res = get_next_line(fd, &line)) == 1)
			if (!(fdf->map[i] = ft_full(fdf->map[i], line, fdf, i)))
				return (0);
		if (res == -1)
			return (0);
		free(line);
	}
	close(fd);
	return (1);
}

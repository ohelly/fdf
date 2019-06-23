/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:33:20 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 17:58:07 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_color(t_map *fdf, char *line, int i, int j)
{
	int		ic;
	int		color;
	int		ind;

	ic = -1;
	ind = 0;
	color = 0;
	if (!(fdf->clc))
	{
		if (!(fdf->clc = (int**)ft_memalloc(sizeof(int*) * fdf->ly)))
			return (0);
		while (++ic < fdf->ly)
			if (!(fdf->clc[ic] = (int*)ft_memalloc(sizeof(int) * fdf->lx)))
				return (0);
	}
	while (line[ind + 1] != ' ')
		ind++;
	color = ft_readcolor(line, ind);
	fdf->clc[i][j] = color;
	return (1);
}

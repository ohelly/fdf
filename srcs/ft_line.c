/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:25 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 18:56:59 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw(t_line *mline, void *win, void *mlx)
{
	mlx_pixel_put(mlx, win, mline->x0, mline->y0, mline->color);
}

static int		ft_ifmin(int length, t_map *fdf, int lengthx, int lengthy)
{
	int d;

	d = -lengthx;
	while (--length)
	{
		draw(fdf->mline, fdf->win, fdf->mlx);
		fdf->mline->x0 += fdf->mline->dx;
		d += 2 * lengthy;
		if (d > 0)
		{
			d -= 2 * lengthx;
			fdf->mline->y0 += fdf->mline->dy;
		}
	}
	return (0);
}

static int		ft_ifmax(int length, t_map *fdf, int lengthx, int lengthy)
{
	int d;

	d = -lengthy;
	while (--length)
	{
		draw(fdf->mline, fdf->win, fdf->mlx);
		fdf->mline->y0 += fdf->mline->dy;
		d += 2 * lengthx;
		if (d > 0)
		{
			d -= 2 * lengthy;
			fdf->mline->x0 += fdf->mline->dx;
		}
	}
	return (0);
}

void			ft_setcolor(t_map *fdf, int i, int j, int c)
{
	if (c == 1)
	{
		if (fdf->clc[i + 1][j] != 0 && fdf->clc[i][j] != 0)
			fdf->mline->color = fdf->clc[i][j];
		else
			fdf->mline->color = 122234;
	}
	else
	{
		if (fdf->clc[i][j + 1] != 0 && fdf->clc[i][j] != 0)
			fdf->mline->color = fdf->clc[i][j];
		else
			fdf->mline->color = 122234;
	}
}

int				ft_line(t_map *fdf, int i, int j, int c)
{
	int lengthx;
	int lengthy;
	int length;

	if (fdf->clc)
		ft_setcolor(fdf, i, j, c);
	lengthx = abs(fdf->mline->x1 - fdf->mline->x0);
	lengthy = abs(fdf->mline->y1 - fdf->mline->y0);
	length = fmax(lengthx, lengthy);
	fdf->mline->dx = (fdf->mline->x1 - fdf->mline->x0 >= 0 ? 1 : -1);
	fdf->mline->dy = (fdf->mline->y1 - fdf->mline->y0 >= 0 ? 1 : -1);
	if (length == 0)
		draw(fdf->mline, fdf->win, fdf->mlx);
	if (lengthy <= lengthx)
		ft_ifmin(++length, fdf, lengthx, lengthy);
	else
		ft_ifmax(++length, fdf, lengthx, lengthy);
	return (0);
}

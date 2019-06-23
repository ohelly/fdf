/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:42:43 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/28 16:33:34 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_drawtoo(t_map *fdf, t_line *mline)
{
	int i;
	int	j;

	i = -1;
	j = -1;
	while (++j < fdf->lx)
	{
		while (++i + 1 < fdf->ly)
		{
			mline->x0 = j * fdf->sh;
			mline->y0 = i * fdf->sh;
			mline->x1 = j * fdf->sh;
			mline->y1 = (i + 1) * fdf->sh;
			ft_rotate(&mline->x0, &mline->y0, fdf->map[i][j], fdf);
			ft_rotate(&mline->x1, &mline->y1, fdf->map[i + 1][j], fdf);
			mline->x0 += fdf->sx;
			mline->y0 += fdf->sy;
			mline->x1 += fdf->sx;
			mline->y1 += fdf->sy;
			ft_line(fdf, i, j, 1);
		}
		i = -1;
	}
	return (1);
}

static int		ft_output1(t_map *fdf, t_line *mline)
{
	int i;
	int	j;

	i = -1;
	j = -1;
	while (++i < fdf->ly)
	{
		while (++j + 1 < fdf->lx)
		{
			mline->x0 = j * fdf->sh;
			mline->y0 = i * fdf->sh;
			mline->x1 = (j + 1) * fdf->sh;
			mline->y1 = i * fdf->sh;
			ft_rotate(&mline->x0, &mline->y0, fdf->map[i][j], fdf);
			ft_rotate(&mline->x1, &mline->y1, fdf->map[i][j + 1], fdf);
			mline->x0 += fdf->sx;
			mline->y0 += fdf->sy;
			mline->x1 += fdf->sx;
			mline->y1 += fdf->sy;
			ft_line(fdf, i, j, 2);
		}
		j = -1;
	}
	return (ft_drawtoo(fdf, mline));
}

int				ft_output(t_map *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_output1(fdf, fdf->mline);
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFFFFFF,
	"[Shift] + Arrows | Moving");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFFF,
	"Arrows and [N] [M]| Rotate");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFFF,
	"[1] and [2] | Appereance");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0xFFFFFF,
	"[+] and [-] | Z Scale");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF,
	"Numpad [+] and [-] or mouse wheel| Zoom");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:58:31 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/28 17:41:41 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init(t_map *fdf)
{
	if (!fdf->mlx && !fdf->win)
	{
		if (!(fdf->mlx = mlx_init()))
			return (0);
		if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "fdf")))
			return (0);
		fdf->sh = 20;
		fdf->sx = SX;
		fdf->sy = SY;
		fdf->gradz = 0;
		fdf->grady = 0;
		fdf->gradx = 0;
		fdf->alt = 1;
		fdf->mline->color = 122234;
		fdf->pr = 1;
	}
	return (1);
}

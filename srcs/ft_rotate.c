/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:33:29 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/28 17:45:00 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_isoz(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x + previous_y) * cos(0.523599);
	*y = -z + (previous_x - previous_y) * sin(0.523599);
}

static void			ft_povorotz(int *x, int *y, int z, t_map *fdf)
{
	int		px;
	int		py;
	int		pz;

	px = *x;
	py = *y;
	pz = z;
	*x = ((px - (fdf->lx * fdf->sh) / 2) * cos((1 / 57.2958) * fdf->gradz)) +
	((py - (fdf->ly * fdf->sh) / 2) * sin((1 / 57.2958) * fdf->gradz));
	*y = ((px - (fdf->lx * fdf->sh) / 2) * sin((1 / 57.2958) * fdf->gradz)) -
	((py - (fdf->ly * fdf->sh) / 2) * cos((1 / 57.2958) * fdf->gradz));
	ft_isoz(x, y, z);
	px = *x;
	py = *y;
	*x = (px * cos((1 / 57.2958) * fdf->grady)) +
	(pz * sin((1 / 57.2958) * fdf->grady));
	z = (pz * cos((1 / 57.2958) * fdf->grady)) -
	(px * sin((1 / 57.2958) * fdf->grady));
	px = *x;
	py = *y;
	pz = z;
	*y = (py * cos((1 / 57.2958) * fdf->gradx)) +
	(pz * sin((1 / 57.2958) * fdf->gradx));
	z = (pz * cos((1 / 57.2958) * fdf->gradx)) -
	(py * sin((1 / 57.2958) * fdf->gradx));
}

int					ft_rotate(int *x, int *y, int z, t_map *fdf)
{
	if (fdf->pr == 1)
		ft_povorotz(x, y, z * fdf->alt, fdf);
	return (0);
}

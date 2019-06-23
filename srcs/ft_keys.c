/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:15:41 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/28 17:46:26 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int button, int x, int y, t_map *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	x = 500;
	y = 500;
	if (button == 4)
		fdf->sh = fdf->sh - 1;
	if (button == 5)
		fdf->sh = fdf->sh + 1;
	return (0);
}

void	ft_grad(int x, t_map *fdf)
{
	if (x == 123)
		fdf->grady -= 1;
	if (x == 124)
		fdf->grady += 1;
	if (x == 126)
		fdf->gradx -= 1;
	if (x == 125)
		fdf->gradx += 1;
	if (x == 45)
		fdf->gradz -= 1;
	if (x == 46)
		fdf->gradz += 1;
}

void	ft_altchange(int x, t_map *fdf)
{
	if (x == 27)
		fdf->alt -= 0.2;
	if (x == 24)
		fdf->alt += 0.2;
	if (x == 69)
		fdf->sh = fdf->sh + 1;
	if (x == 78)
		fdf->sh = fdf->sh - 1;
}

int		key_press(int x, t_map *fdf)
{
	static int	shift = 0;

	if (x == -1)
		shift = 0;
	if (x == 257)
		shift = 1;
	if (x == 69 || x == 78)
		ft_altchange(x, fdf);
	if (shift && x == 126)
		fdf->sy -= 5;
	if (shift && x == 125)
		fdf->sy += 5;
	if (shift && x == 123)
		fdf->sx -= 5;
	if (shift && x == 124)
		fdf->sx += 5;
	if ((x == 123 || x == 124 || x == 126 || x == 125) && !shift)
		ft_grad(x, fdf);
	if (x == 45 || x == 46)
		ft_grad(x, fdf);
	if (x == 27 || x == 24)
		ft_altchange(x, fdf);
	return (0);
}

int		key_realease(int key, t_map *fdf)
{
	if (key == 257)
		key_press(-1, fdf);
	if (key == 53)
		return (cloose(fdf));
	if (key == 18)
		fdf->pr = 1;
	if (key == 19)
		fdf->pr = 2;
	return (0);
}

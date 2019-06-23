/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:14:13 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/24 17:03:06 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_hook(t_map *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, key_press, fdf);
	mlx_hook(fdf->win, 3, 1L << 1, key_realease, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, mouse_press, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, cloose, fdf);
	mlx_loop_hook(fdf->mlx, ft_output, fdf);
	mlx_loop(fdf->mlx);
}

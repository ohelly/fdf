/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cloose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:11:41 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 15:12:03 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cloose(t_map *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_window(fdf->mlx, fdf->win);
	ft_free(fdf);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:45:38 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 18:02:31 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freemap(t_map *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->ly)
		if (fdf->map[i])
			free(fdf->map[i]);
	free(fdf->map);
	fdf->map = 0;
}

void	ft_freeclc(t_map *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->ly)
		if (fdf->clc[i])
			free(fdf->clc[i]);
	free(fdf->clc);
	fdf->clc = 0;
}

int		ft_free(t_map *fdf)
{
	if (!fdf)
		return (0);
	if (fdf->map)
		ft_freemap(fdf);
	if (fdf->mline)
		free(fdf->mline);
	if (fdf->clc)
		ft_freeclc(fdf);
	free(fdf);
	fdf = 0;
	return (0);
}

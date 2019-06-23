/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:18:51 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/26 18:07:23 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*ft_initall(t_map *fdf, int ac, char **av)
{
	if (!(fdf = (t_map*)ft_memalloc(sizeof(t_map))))
		return (0);
	if (!(fdf->mline = (t_line*)ft_memalloc(sizeof(t_line))))
		return (0);
	if (!(ft_checkvalid(ac, av, fdf)))
		return (0);
	if (!(ft_fullmap(fdf, av[1])))
		return (0);
	if (!(ft_init(fdf)))
		return (0);
	if (!(ft_output(fdf)))
		return (0);
	return (fdf);
}

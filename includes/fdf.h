/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:06 by ohelly            #+#    #+#             */
/*   Updated: 2019/04/28 16:55:22 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <ctype.h>
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include "const.h"
# define BUFF_SIZE 1

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				color;
}					t_line;

typedef struct		s_map
{
	int				lx;
	int				ly;
	int				sh;
	int				sx;
	int				sy;
	int				pr;
	int				gradz;
	int				grady;
	int				gradx;
	int				**map;
	int				**clc;
	void			*mlx;
	void			*win;
	double			alt;
	t_line			*mline;
}					t_map;

int					get_next_line(int const fd, char **line);
int					ft_free(t_map *fdf);
int					ft_readcolor(char *str, int ind);
int					ft_line(t_map *fdf, int i, int j, int c);
int					ft_output(t_map *fdf);
int					ft_checkvalid(int ac, char **av, t_map *fdf);
int					ft_fullmap(t_map *fdf, char *av);
int					ft_init(t_map *fdf);
int					ft_get_color(t_map *fdf, char *line, int i, int j);
int					key_press(int x, t_map *fdf);
int					key_realease(int key, t_map *fdf);
int					mouse_press(int button, int x, int y, t_map *fdf);
int					ft_rotate(int *x, int *y, int z, t_map *fdf);
int					cloose(t_map *fdf);
void				ft_hook(t_map *fdf);
t_map				*ft_initall(t_map *fdf, int ac, char **av);

#endif

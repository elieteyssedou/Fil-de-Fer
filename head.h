/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 18:08:36 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/24 18:08:36 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
#include <stdio.h>
# include <math.h>

# define Z (cos(x));

typedef struct 		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_pos
{
	int				x;
	int 			y;
}					t_pos;

typedef struct		s_3dpos
{
	int				x;
	int 			y;
	int				z;
}					t_3dpos;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

void	ft_perfect_line_put(t_env env, t_pos start, t_pos end, t_color color);
void	ft_direct_x_line(t_env env, t_pos start, t_pos end, t_color color);
void	ft_direct_y_line(t_env env, t_pos start, t_pos end, t_color color);
void	ft_line_put(t_env env, t_pos start, t_pos end, t_color color);
void	ft_red_square(int x, int y, t_env env);
void	ft_green_square(int x, int y, t_env env);
void	ft_blue_square(int x, int y, t_env env);
void	ft_clear_square(int x, int y, t_env env);
void	ft_clear_screen(t_env env);
int		ft_color_to_int(t_color color);
void	ft_put_pixel(t_env env, t_pos point, t_color color);
void	ft_line_put(t_env env, t_pos p1, t_pos p2, t_color color);
void	ft_put_square(t_env env, t_pos p1, t_pos p2, t_color color, int i);
void	ft_fill_square(t_env env, t_pos p1, t_pos p2, t_color color);
t_pos	ft_3d_to_2d(t_3dpos dp1);
t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b);
void	ft_3d_line_put(t_env env, t_3dpos dp1, t_3dpos dp2, t_color color);
t_3dpos	ft_new_3d_pos(int x, int y, int z);
void	ft_3d_gen_tab(t_3dpos tab[][20], int e, int v);
void	ft_put_3d_tab(t_env env, t_3dpos tab[][20], t_color color);
void	ft_cp_tab(t_3dpos tab[][20], t_3dpos tab2[][20]);

#endif

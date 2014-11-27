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

typedef struct 	s_env
{
	void		*mlx;
	void		*win;
	int			lx;
	int			ly;
	int			rx;
	int			ry;
	int			bx;
	int			by;
}				t_env;

typedef struct	s_pos
{
	int			x;
	int 		y;
}				t_pos;

typedef struct  s_color
{
	char	r;
	char	g;
	char	b;
}				t_color;

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

#endif

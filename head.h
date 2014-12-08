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
# include <math.h>
# include "libft/get_next_line.h"

# include <stdio.h> //A ENLEVER

# define SIZE_WIN_X 720
# define SIZE_WIN_Y 720
# define GAP 5
# define ALT 7

typedef unsigned char	t_byte;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct s_img
{
	void		*img;
	int			bpp;
	int			sizeline;
	int         endian;
	int			clrline;
	char		*data;
}				t_img;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_3dpos
{
	int			x;
	int			y;
	int			z;
}				t_3dpos;

typedef struct	s_all
{
	t_env		env;
	t_3dpos		**tab;
	t_pos		max;
	t_img		img;
	t_pos		posimg;
	int			re;
	int			alt;
	int			zoom;
	int			r;
}				t_all;

typedef struct	s_color
{
	t_byte		r;
	t_byte		g;
	t_byte		b;
}				t_color;

typedef struct	s_line
{
	t_pos		p1;
	t_pos		p2;
	t_color		clr;
	t_pos		inc;
	int			dx;
	int			dy;
}				t_line;

int				ft_color_to_int(t_color color);
void			ft_put_pixel(t_env env, t_pos point, t_color color);
void			ft_line_put(t_all *all, t_pos p1, t_pos p2, t_img img);
void			ft_line_put_1(t_all *all, t_line line, t_img img);
void			ft_line_put_2(t_all *all, t_line line, t_img img);
void			ft_3d_line(t_all *all, t_3dpos dp1, t_3dpos dp2, t_img img);
void			ft_put_3d_tab(t_all *all);
void			ft_end_line(t_all *all, t_3dpos **tab, t_img img, t_pos max);
t_pos			ft_3d_to_2d(t_3dpos dp1);
t_color			ft_rgb_to_color(t_byte r, t_byte g, t_byte b);
t_3dpos			**ft_fill_tab(t_list *lst, t_3dpos pt);
t_all			ft_read_map(int fd, char c);
void			ft_put_pixel_img(t_env env, t_pos point, t_img img);
void			color_alt(t_all *all, int z);
void			move_up(t_all *all);
void			move_down(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);

#endif

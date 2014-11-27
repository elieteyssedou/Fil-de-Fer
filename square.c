/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:04:44 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/25 15:04:45 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_fill_square(t_env env, t_pos p1, t_pos p2, t_color color)
{
	t_pos c1;
	t_pos c2;

	c1.x = p2.x;
	c1.y = p1.y;
	c2.x = p1.x;
	c2.y = p2.y;
	if (p1.x > p2.x)
	{
		c1.x = p2.x;
		p2.x = p1.x;
		p1.x = c1.x;
	}
	if (p1.y > p2.y)
	{
		c1.y = p2.y;
		p2.y = p1.y;
		p1.y = c1.y;
	}
	while (p1.y != p2.y)
	{
		p1.x = c2.x;
		while (p1.x != p2.x)
		{
			ft_put_pixel(env, p1, color);
			p1.x++;
		}
		p1.y++;
	}
}

void	ft_put_square(t_env env, t_pos p1, t_pos p2, t_color color, int i)
{
	t_pos c1;
	t_pos c2;

	c1.x = p2.x;
	c1.y = p1.y;
	c2.x = p1.x;
	c2.y = p2.y;
	ft_line_put(env, p1, c1, color);
	ft_line_put(env, c1, p2, color);
	ft_line_put(env, p2, c2, color);
	ft_line_put(env, c2, p1, color);
	
	if (i > 0 && p1.x < p2.x)
		ft_fill_square(env, p1, p2, color);
	else if (i > 0 && p1.x > p2.x)
		ft_fill_square(env, p2, p1, color);
}







void	ft_red_square(int x, int y, t_env env)
{
	int tx;
	int ty;

	tx = x - 5;
	ty = y - 5;
	while (ty != y + 5)
	{
		tx = x - 5;
		while (tx != x + 5)
		{
			mlx_pixel_put(env.mlx, env.win, tx, ty, 0xFF0000);
			tx++;
		}
		ty++;
	}
}

void	ft_green_square(int x, int y, t_env env)
{
	int tx;
	int ty;

	tx = x - 5;
	ty = y - 5;
	while (ty != y + 5)
	{
		tx = x - 5;
		while (tx != x + 5)
		{
			mlx_pixel_put(env.mlx, env.win, tx, ty, 0x00FF00);
			tx++;
		}
		ty++;
	}
}

void ft_blue_square(int x, int y, t_env env)
{
	int tx;
	int ty;
	static int ox;
	static int oy;

	tx = ox - 5;
	ty = oy - 5;
	while (ty != oy + 5)
	{
		tx = ox - 5;
		while (tx != ox + 5)
		{
			mlx_pixel_put(env.mlx, env.win, tx, ty, 0x0000FF);
			tx++;
		}
		ty++;
	}
	ox = x;
	oy = y;
}

void ft_clear_square(int x, int y, t_env env)
{
	int tx;
	int ty;
	static int ox;
	static int oy;

	tx = ox - 5;
	ty = oy - 5;
	while (ty != oy + 5)
	{
		tx = ox - 5;
		while (tx != ox + 5)
		{
			mlx_pixel_put(env.mlx, env.win, tx, ty, 0x000000);
			tx++;
		}
		ty++;
	}
	ox = x;
	oy = y;
}

void ft_clear_screen(t_env env)
{
	int x;
	int y;

	y = 0; 
	while (y != 480)
	{
		x = 0;
		while (x != 480)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}	
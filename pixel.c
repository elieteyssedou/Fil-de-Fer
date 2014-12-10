/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:03:26 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/01 17:03:27 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int		ft_color_to_int(t_color color)
{
	int c;

	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

void	ft_put_pixel(t_env env, t_pos point, t_color color)
{
	mlx_pixel_put(env.mlx, env.win, point.x, point.y, ft_color_to_int(color));
}

void	ft_put_pixel_img(t_env env, t_pos point, t_img img)
{
	env = env;

	if((point.x >= 0 && point.x <= SIZE_WIN_X)
		&& (point.y >= 0 && point.y <= SIZE_WIN_Y))
		ft_memcpy(&img.data[(point.y * img.sizeline) + (point.x * 4)], &img.clrline, (size_t)(sizeof(int)));
}

void	ft_put_3d_tab(t_env env, t_3dpos **tab, t_img img, t_pos max)
{
	int	x;
	int	y;

	y = 0;
	while (y < (max.y - 1))
	{
		x = 0;
		while (x < (max.x - 1))
		{
			ft_3d_line(env, tab[y][x], tab[y][x + 1], img);
			ft_3d_line(env, tab[y][x], tab[y + 1][x], img);
			x++;
		}
		y++;
	}
	ft_end_line(env, tab, img, max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:06:22 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/08 14:06:22 by eteyssed         ###   ########.fr       */
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
	if ((point.x >= 0 && point.x <= SIZE_WIN_X)
		&& (point.y >= 0 && point.y <= SIZE_WIN_Y))
		ft_memcpy(&img.data[(point.y * img.sizeline) + (point.x * 4)],\
			&img.clrline, (size_t)(sizeof(int)));
}

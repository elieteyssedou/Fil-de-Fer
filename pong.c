/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:03:12 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/25 17:03:13 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_left_bar(int x, int y, t_env env)
{
	int tx;
	int ty;

	tx = x - 5;
	ty = y - 10;
	while (ty != y + 10)
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

ft_clear_left_bar(int x, int y, t_env env)
{
	static int ox;
	static int oy;

	int tx;
	int ty;

	tx = ox - 5;
	ty = oy - 10;
	while (ty != oy + 10)
	{
		tx = ox - 5;
		while (tx != ox + 5)
		{
			mlx_pixel_put(env.mlx, env.win, ox, oy, 0x000000);
			tx++;
		}
		ty++;
	}
	ox = x;
	oy = y;
}
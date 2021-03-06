/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:51:10 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/24 17:51:31 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	allinit(t_all *all)
{
	all->re = 1;
	all->alt = 1;
	all->posimg.x = (SIZE_WIN_X / 2);
	all->posimg.y = (SIZE_WIN_Y / 2);
	all->zoom = GAP;
	all->rx = 2;
	all->ry = 2;
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		all->alt += 1;
		all->zoom++;
		all->re = 1;
	}
	if (button == 3)
	{
		if (all->alt != 1)
			all->alt -= 1;
		if (all->zoom)
			all->zoom--;
		all->re = 1;
	}
	return (0);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
		all->re = -1;
	if (keycode == 65362)
		move_up(all);
	if (keycode == 65364)
		move_down(all);
	if (keycode == 65361)
		move_left(all);
	if (keycode == 65363)
		move_right(all);
	if (keycode == 65451)
	{
		all->alt += 1;
		all->re = 1;
	}
	if (keycode == 65453)
	{
		if (all->alt)
			all->alt -= 1;
		all->re = 1;
	}
	if (keycode == 65464)
	{
		if (all->rx != -1 || all->ry != -1)
		{
			all->rx += 1;
			all->ry += 1;
		}
		all->re = 1;
	}
	if (keycode == 65458)
	{
		if (all->rx != 0.5 || all->ry != 0.5)
		{
			all->rx -= 0.5;
			all->ry -= 0.5;
		}
		all->re = 1;
	}
	if (keycode == 65465)
	{
		all->zoom++;
		all->re = 1;
	}
	if (keycode == 65462)
	{
		if (all->zoom)
			all->zoom--;
		all->re = 1;
	}
	return (0);
}

int		loop_hook(t_all *all)
{
	if(all->re)
	{
		if (all->re == -1)
			ft_free_all(all);
		ft_bzero(all->img.data, 4 * SIZE_WIN_X * SIZE_WIN_Y);
		ft_put_3d_tab(all);
		mlx_put_image_to_window(all->env.mlx, all->env.win,\
			all->img.img, 0, 0);
		mlx_string_put(all->env.mlx, all->env.win, 10, 20, 0x98CD00,\
			"Height change : +/-.");
		mlx_string_put(all->env.mlx, all->env.win, 10, 40, 0x98CD00,\
			"Zoom : Scroll mouse");
		mlx_string_put(all->env.mlx, all->env.win, 10, 60, 0x98CD00,\
			"Navigation : Arrows");
		all->re = 0;
	}
	return (0);
}

int main(int ac, char **av)
{
	ac = ac;
	av = av;
	t_all	*all;
	int		fd;

	ft_ac_error(ac);
	fd = open(av[1], O_RDONLY);
	ft_is_fd(fd, av[1]);
	all = (t_all *)malloc(sizeof(all));
	*all = ft_read_map(fd, ' ');
	all->env.mlx = mlx_init();
	all->env.win = mlx_new_window(all->env.mlx, SIZE_WIN_X, SIZE_WIN_Y, "42 FDF");
	all->img.img = mlx_new_image(all->env.mlx, SIZE_WIN_X, SIZE_WIN_Y);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp, &all->img.sizeline, &all->img.endian);
	all->img.clrline = 0x000000;
	all->name = av[1];
	allinit(all);
	mlx_key_hook(all->env.win, key_hook, all);
	mlx_loop_hook(all->env.mlx, loop_hook, all);
	mlx_mouse_hook(all->env.win, mouse_hook, all);
	mlx_expose_hook(all->env.win, expose_hook, all);
	mlx_loop(all->env.mlx);
	return (0);
}

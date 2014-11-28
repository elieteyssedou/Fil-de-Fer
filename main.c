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

int	mouse_hook(int button, int x, int y, t_env *env)
{
	static t_pos	p1;
	static t_pos	p2;
	t_color 	color;
	static	int i;

	color.r = 0xFF;
	color.g = 99;
	color.b = 99;

	ft_blue_square(-10, -10, *env);
	if (button == 1)
	{
		p1.x = x;
		p1.y = y;
		ft_put_square(*env, p1, p2, color, i);
	}
	else if (button == 3)
	{
		p2.x = x;
		p2.y = y;
		ft_green_square(x, y, *env);
	}
	else if (button == 2)
	{
		if(i == 0)
			i = 1;
		else
			i = 0;
	}
	return (0);
}

int	key_hook (int keycode, t_env *env)
{
	//static int ox;

	env = env;
	if (keycode == 65307)
		exit(0);
	// else
	// {	
	// 	t_3dpos tab[10][100];
	// 	static t_color blue = {0, 0, 0xFF};

	// 	blue.g += 10;
	// 	t_color black = {0, 0, 0};

	// 	if (ox < 500)
	// 		ox += 10;
	// 	ft_3d_gen_tab(tab, 20, ox);
	// 	ft_put_3d_tab(*env, tab, blue);

	// 	ft_3d_gen_tab(tab, 20, ox - 10);
	// 	ft_put_3d_tab(*env, tab, black);

	// 	ft_3d_gen_tab(tab, 20, ox);
	// 	ft_put_3d_tab(*env, tab, blue);
	// }
	return (0);
}

void	ft_cp_tab(t_3dpos tab[][20], t_3dpos tab2[][20])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			tab2[x][y] = tab[x][y];
			x++;
		}
		y++;
	}
}

int loop_hook(t_env *env)
{
	static int ox;
	static int tg = 0;
	static int tb = 0;
	static int tr = 0;
	static t_3dpos tab[20][20];
	static t_3dpos tab2[20][20];
	static t_color blue = {0, 0, 0};
	t_color black = {0, 0, 0};
	// t_pos p1 = {0,0};
	// t_pos p2 = {2400, 1200};

	if (tg == 0)
	{
		blue.g += 5;
		if (blue.g >= 243)
			tg = 1;
	}
	else
	{
		blue.g -= 5;
		if (blue.g < 50)
			tg = 0;
	}

	if (tr == 0)
	{
		blue.r += 1;
		if (blue.r >= 243)
			tr = 1;
	}
	else
	{
		blue.r -= 1;
		if (blue.r <50)
			tr = 0;
	}

	if (tb == 0)
	{
		blue.b += 2;
		if (blue.b >= 243)
			tr = 1;
	}
	else
	{
		blue.b -= 2;
		if (blue.b < 50)
			tr = 0;
	}

	if (ox < 20000)
		ox += 1;
	ft_3d_gen_tab(tab, 60, ox);
	ft_put_3d_tab(*env, tab2, black);
	ft_put_3d_tab(*env, tab, blue);
	ft_cp_tab(tab, tab2);
	usleep(20000);
	//usleep(2000);
	return (0);
}

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

t_3dpos	ft_new_3d_pos(int x, int y, int z)
{
	t_3dpos dp1;

	dp1.x = x;
	dp1.y = y;
	dp1.z = z;
	return (dp1);
}

void	ft_3d_gen_tab(t_3dpos tab[][20], int e, int v)
{
	int x;
	int y;
	//int z;

	x = 0;
	y = 0;
	//z = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			tab[x][y] = ft_new_3d_pos(x * e + 650, y *e - 500, ((cos(((x + (v/5.0)) / 2.0)) + (-sin(((y + (v/5.0)) / 2.0)))) * 60));
			x++;
		}
		y++;
	}
}

void	ft_put_3d_tab(t_env env, t_3dpos tab[][20], t_color color)
{
	int x;
	int y;



	y = 0;
	while (y < 19)
	{
		x = 0;
		while (x < 19)
		{
			ft_3d_line_put(env, tab[y][x], tab[y][x + 1], color);
			ft_3d_line_put(env, tab[y][x], tab[y + 1][x], color);	
			x++;
		}
		y++;
	}
}

int main (int ac, char **av)
{
	ac = ac;
	av = av;
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window (env.mlx, 2400, 1200, "42 FDF");
	
	//t_color blue = {0, 0, 0xFF};
	// t_3dpos tab[10][10];
	// ft_3d_gen_tab(tab, 20, 10);
	// ft_put_3d_tab(env, tab, blue);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	// mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
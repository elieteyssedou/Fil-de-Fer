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
	int cpy;
	static int i;
	static int x = 240;
	static int y = 240;

	cpy = i;
	env = env;
	if (keycode == 65307)
		exit(0);
	else if(keycode == 65361)
	{
		while (cpy != i+6)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
			x--;
			cpy++;
		}
		i = cpy;
	}
	else if(keycode == 65363)
	{
		while (cpy != i+6)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
			x++;
			cpy++;
		}
		i = cpy;
	}
	else if(keycode == 65362)
	{
		while (cpy != i+6)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
			y--;
			cpy++;
		}
		i = cpy;
	}
	else if(keycode == 65364)
	{
		while (cpy != i+6)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
			y++;
			cpy++;
		}
		i = cpy;
	}
	return (0);
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

int main (int ac, char **av)
{
	ac = ac;
	av = av;
	t_env	env;
	// t_pos	start;
	// t_pos	end;
	// t_color	color;

	// start.x = ft_atoi(av[1]);
	// start.y = ft_atoi(av[2]);
	// end.x = ft_atoi(av[3]);
	// end.y = ft_atoi(av[4]);
	// color.t = 0xFF0000;

	env.mlx = mlx_init();
	env.win = mlx_new_window (env.mlx, 480, 480, "42 FDF");
	//ft_line_put(env, start, end, color);
	
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
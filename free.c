/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 18:05:37 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/10 18:05:38 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	cartridge(t_all *all)
{
	mlx_string_put(all->env.mlx, all->env.win, ((SIZE_WIN_X / 2) - 198), 20, \
		0xF65B0A, \
		"                               FIL DE FER                              ");
	mlx_string_put(all->env.mlx, all->env.win, ((SIZE_WIN_X / 2) - 198), 20, \
		0x98CD00, \
		"<-----------------------------            ---------------------------->");
	mlx_string_put(all->env.mlx, all->env.win, 10, 30, 0xF65B0A,\
		"Map Name :");
	mlx_string_put(all->env.mlx, all->env.win, 76, 30, 0x98CD00,\
		all->name);
	mlx_string_put(all->env.mlx, all->env.win, 10, 50, 0xF65B0A,\
		"Height Change : +/- .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 70, 0xF65B0A,\
		"Zoom : Scroll Mouse .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 90, 0xF65B0A,\
		"View Adjustmt : 6/9 .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 110, 0xF65B0A,\
		"Navigation : Arrows .");
	mlx_string_put(all->env.mlx, all->env.win, 10, 130, 0xF65B0A,\
		"Reset Image : Enter .");
}

void			ft_free_map(t_all *all)
{
	while (all->max.y--)
		free(all->tab[all->max.y--]);
	free(all->tab);
}

void			ft_free_all(t_all *all)
{
	ft_free_map(all);
	mlx_destroy_image(all->env.mlx, all->img.img);
	free(all->env.mlx);
	free(all->env.win);
	free(all);
	exit (0);
}

void	ft_ac_error(int ac)
{
	if (ac != 2)
	{
		ft_putendl_fd("fdf: Usage: <example.fdf>", 2);
		exit (0);
	}
}

void	ft_is_fd(int fd, char *av)
{
	if (fd == -1)
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putstr_fd(&av[1], 2);
		ft_putendl_fd(": Does not exists or is invalid.", 2);
		exit (0);
	}
}
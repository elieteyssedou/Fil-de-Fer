/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:39:10 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/08 15:39:11 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int				expose_hook(t_all *all)
{
	mlx_put_image_to_window(all->env.mlx, all->env.win,\
		all->img.img, 0, 0);
	cartridge(all);
	return (0);
}

void	color_alt(t_all *all, int z)
{
if (all->alt == 0)
		all->img.clrline = 0x7FC6BC;
	else if ((-z / all->alt) <= -4)
		all->img.clrline = 0x3D8189;
	else if ((-z / all->alt) <= -2)
		all->img.clrline = 0x4BB5C1;
	else if ((-z / all->alt) <= 0)
		all->img.clrline = 0x7FC6BC;
	else if ((-z / all->alt) <= 1)
		all->img.clrline = 0xffe58a;
	else if ((-z / all->alt) <= 4)
		all->img.clrline = 0x71A12F;
	else if ((-z / all->alt) <= 6)
		all->img.clrline = 0x557A23;
	else if ((-z / all->alt) <= 8)
		all->img.clrline = 0x896A45;
	else if ((-z / all->alt) <= 10)
		all->img.clrline = 0xA98458;
	else if ((-z / all->alt) <= 12)
		all->img.clrline = 0xCAA986;
	else
		all->img.clrline = 0xEDF7F2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:03:26 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/01 17:03:27 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_pos	ft_3d_to_2d(t_3dpos dp1, float rx, float ry)
{
	t_pos p1;

	p1.x = dp1.x - dp1.y;
	p1.y = dp1.z + (dp1.x / rx) + (dp1.y / ry);
	return (p1);
}

t_3dpos	ft_new_3d_pos(int x, int y, int z)
{
	t_3dpos dp1;

	dp1.x = x;
	dp1.y = y;
	dp1.z = z;
	return (dp1);
}

void	ft_put_3d_tab(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	color_alt(all, ((all->tab[0][0].z + all->tab[0][1].z) / 2));
	while (y < (all->max.y - 1))
	{
		x = 0;
		while (x < (all->max.x - 1))
		{
			ft_3d_line(all, all->tab[y][x], all->tab[y][x + 1]);
			ft_3d_line(all, all->tab[y][x], all->tab[y + 1][x]);
			x++;
		}
		y++;
	}
	ft_end_line(all, all->tab, all->max);
}

void	ft_end_line(t_all *all, t_3dpos **tab, t_pos max)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y + 1 < max.y)
	{
		ft_3d_line(all, tab[y][max.x - 1], tab[y + 1][max.x - 1]);
		y++;
	}
	while (x + 1 < max.x)
	{
		ft_3d_line(all, tab[max.y - 1][x], tab[max.y - 1][x + 1]);
		x++;
	}
}

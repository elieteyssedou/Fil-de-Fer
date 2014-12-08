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

// void	ft_fill_rect(t_all all)
// {
	
// }

void	color_alt(t_all *all, int z)
{
	if (all->alt == 0)
		all->img.clrline = 0x7FC6BC;
	else if ((-z / all->alt) <= -2)
		all->img.clrline = 0x4BB5C1;
	else if ((-z / all->alt) <= 0)
		all->img.clrline = 0x7FC6BC;
	else if ((-z / all->alt) <= 4)
		all->img.clrline = 0x93B550;
	else if ((-z / all->alt) <= 6)
		all->img.clrline = 0x98CC50;
	else if ((-z / all->alt) <= 8)
		all->img.clrline = 0xB39167;
	else if ((-z / all->alt) <= 10)
		all->img.clrline = 0xBA9D7A;
	else if ((-z / all->alt) <= 12)
		all->img.clrline = 0xCAA986;
	else
		all->img.clrline = 0xEDF7F2;
}
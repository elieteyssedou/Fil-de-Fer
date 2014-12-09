/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:41:46 by eteyssed          #+#    #+#             */
/*   Updated: 2014/12/08 17:42:27 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void			move_up(t_all *all)
{
	all->posimg.y -= 5;
	all->re = 1;
}

void			move_down(t_all *all)
{
	all->posimg.y += 5;
	all->re = 1;
}

void			move_left(t_all *all)
{
	all->posimg.x -= 5;
	all->re = 1;
}

void			move_right(t_all *all)
{
	all->posimg.x += 5;
	all->re = 1;
}

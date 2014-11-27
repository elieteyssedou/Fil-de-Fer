/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:35:12 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/25 13:35:12 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_pos	ft_3d_to_2d(t_3dpos dp1)
{
	float cst1 = 1;
	float cst2 = 1;
	t_pos p1;

	p1.x = (cst1 * dp1.x) - (cst2 * dp1.y);
	p1.y = dp1.z + ((cst1 / 2) * dp1.x) + ((cst2 / 2) * dp1.y);

	return (p1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void ft_line_put(t_env env, t_pos p1, t_pos p2, t_color color)
{
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;

	p2.x -= p1.x;
	p2.y -= p1.y;
	xinc = (p2.x > 0) ? 1 : -1;
	yinc = (p2.y > 0) ? 1 : -1;
	p2.x = ft_abs(p2.x) ;
	p2.y = ft_abs(p2.y) ;
  	ft_put_pixel(env, p1, color);
  	i = 1;
  	if (p2.x > p2.y)
  	{
    	cumul = p2.x / 2 ;
    	while (i <= p2.x)
    	{
			p1.x += xinc ;
			cumul += p2.y ;
			if ( cumul >= p2.x )
			{
				cumul -= p2.x ;
				p1.y += yinc;
			}
    	  	ft_put_pixel(env, p1, color); 
 			i++;
 		}
 	}
    else
    {
    	cumul = p2.y / 2;
    	while (i <= p2.y)
    	{
			p1.y += yinc;
			cumul += p2.x;
			if ( cumul >= p2.y )
			{
				cumul -= p2.y;
				p1.x += xinc;
			}
				ft_put_pixel(env, p1, color);
			i++;
  		}
	}
}

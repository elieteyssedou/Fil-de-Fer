/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:09:24 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/28 19:38:19 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_3dpos			**ft_fill_tab(t_list *lst, t_3dpos pt)
{
	t_3dpos		**tab;
	int			i;

	i = 0;
	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.y);
	while (i < pt.y)
		tab[i++] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.x);
	while (lst)
	{
		pt = *((t_3dpos*)lst->content);
		pt.z = -pt.z;
		tab[pt.y][pt.x] = pt;
		lst = lst->next;
	}
	return (tab);
}

t_all			ft_read_map(int fd, char c)
{
	char		*tmp;
	char		**tabx;
	t_3dpos		pt;
	t_list		*lst;
	t_all		all;

	lst = NULL;
	pt.y = 0;
	while (get_next_line(fd, &tmp))
	{
		pt.x = 0;
		tabx = ft_strsplit(tmp, c);
		free(tmp);
		while (*tabx)
		{
			pt.z = ft_atoi(*tabx++);
			ft_lstadd(&lst, ft_lstnew(&pt, sizeof(t_3dpos)));
			pt.x++;
		}
		pt.y++;
	}
	all.tab = ft_fill_tab(lst, pt);
	all.max.x = pt.x;
	all.max.y = pt.y;
	return (all);
}

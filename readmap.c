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
	int			erno;
	t_list		*lst;
	t_all		all;

	lst = NULL;
	all.max.y = 0;
	while ((erno = get_next_line(fd, &tmp)))
	{
		ft_dir_err(erno);
		all.max.x = 0;
		tabx = ft_strsplit(tmp, c);
		free(tmp);
		while (*tabx)
		{
			all.max.z = ft_atoi(*tabx);
			ft_lstadd(&lst, ft_lstnew(&all.max, sizeof(t_3dpos)));
			all.max.x++;
			free(*tabx++);
		}
		all.max.y++;
	}
	all.tab = ft_fill_tab(lst, all.max);
	return (all);
}

void			ft_dir_err(int erno)
{
	if (erno == -1)
	{
		ft_putstr_fd("fdf: The file you tried to open is a directory. ", 2);
		ft_putendl_fd("Put a valid map as argument.", 2);
		exit (0);
	}
}

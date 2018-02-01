/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:38:05 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 15:58:44 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		room_number(t_lemin *data)
{
	t_room		*tmp;
	int			count;

	tmp = data->rooms;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static t_room	*get_start(t_lemin *data)
{
	t_room		*tmp;

	tmp = data->rooms;
	while (ft_strcmp(tmp->name, data->start))
		tmp = tmp->next;
	return (tmp);
}

static int		check_double(t_lemin *data, t_list *room, int check)
{
	int			index;

	index = 0; 
	while (index < check)
	{
		if (data->path[index] == room)
			return (1);
		index++;
	}
	return (0);
}

static int		backtrack(t_lemin *data, t_list *tmp, int rn)
{
	int			index;

	index = 1;
	while (tmp)
	{
		data->path[index] = tmp;
		if (check_double(data, data->path[index], index))
			return (0);
		tmp = tmp->next;
	}
}

void			get_path(t_lemin *data)
{
	int			rn;
	int			index;
	t_list		*tmp;

	rn = room_number(data);
	if (!(data->path = (t_room**)ft_memalloc(sizeof(t_room*) * (rn + 1))))
		failure();
	data->path[0] = get_start(data);
	tmp = (data->path)[0]->lk_rooms;
	if (backtrack(data, tmp, rn) == -1)
		failure();
}

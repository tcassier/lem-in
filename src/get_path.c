/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:38:05 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/03 18:55:05 by tcassier         ###   ########.fr       */
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

static void		*get_start(t_lemin *data)
{
	t_room		*tmp;
	t_list		*new;

	if (!(new = ft_lstnew(NULL, 0)))
		failure();
	tmp = data->rooms;
	while (ft_strcmp(tmp->name, data->start))
		tmp = tmp->next;
	new->content = (void*)tmp;
	return (new);
}

static int		check_double(t_lemin *data, t_room *room, int check)
{
	int			index;

	index = 0;
	while (index < check)
	{
		if ((t_room*)data->path[index]->content == room)
			return (1);
		index++;
	}
	return (0);
}

static int		backtrack(t_lemin *data, t_list *tmp, int index)
{
	while (tmp)
	{
		data->path[index] = tmp;
		if (!check_double(data, (t_room*)tmp->content, index))
		{
			if (!ft_strcmp(((t_room*)tmp->content)->name, data->end) ||
			backtrack(data, ((t_room*)tmp->content)->lk_rooms, index + 1))
				return (1);
			else
				data->path[index] = NULL;
		}
		else
			data->path[index] = NULL;
		tmp = tmp->next;
	}
	return (0);
}

void			get_path(t_lemin *data)
{
	t_list		*tmp;

	if (!(data->path = (t_list**)ft_memalloc(sizeof(t_list*)
	* (room_number(data) + 1))))
		failure();
	data->path[0] = get_start(data);
	tmp = ((t_room*)data->path[0]->content)->lk_rooms;
	if (!backtrack(data, tmp, 1))
		failure();
}

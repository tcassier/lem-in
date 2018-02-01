/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:53:01 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 10:53:47 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_double(t_lemin *data)
{
	t_room	*tmp_1;
	t_room	*tmp_2;

	tmp_1 = data->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1;
		while (tmp_2->next)
		{
			if (!ft_strcmp(tmp_1->name, tmp_2->next->name))
				failure();
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
}

static void		check_hash(t_lemin *data, t_list *tmp)
{
	char		*str;
	char		**tab;

	if (!(str = ft_strtrim((char*)tmp->content)))
		failure();
	if (!ft_strcmp("##start", str) || !ft_strcmp("##end", str))
	{
		if (tmp->next && ft_count_word((char*)tmp->next->content, ' ') == 3)
		{
			if (!(tab = ft_strsplit((char*)tmp->next->content, ' ')))
				failure();
			if (!ft_strcmp("##start", str))
				data->start = tab[0];
			else
				data->end = tab[0];
			tab_del(tab + 1);
			free(tab);
		}
		else
			failure();
	}
	free(str);
}

static void		check_data(t_lemin *data, t_list *tmp)
{
	char		**tab;
	t_room		*new;

	if (!(new = (t_room*)ft_memalloc(sizeof(t_room))))
		failure();
	if (!(tab = ft_strsplit((char*)tmp->content, ' ')))
		failure();
	new->name = tab[0];
	new->next = data->rooms;
	data->rooms = new;
	if (!is_int(tab[1]) || !is_int(tab[2]))
		failure();
	tab_del(tab + 1);
	free(tab);
}

t_list			*check_rooms(t_lemin *data, t_list *tmp)
{
	while (tmp && (ft_count_word((char*)tmp->content, ' ') == 3 ||
	((char*)tmp->content)[0] == '#'))
	{
		if (((char*)tmp->content)[0] == '#')
			check_hash(data, tmp);
		else
			check_data(data, tmp);
		tmp = tmp->next;
	}
	check_double(data);
	return (tmp);
}

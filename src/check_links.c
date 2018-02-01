/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 08:05:43 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 10:12:44 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_double(t_lemin *data)
{
	t_room	*tmp_1;
	t_list	*tmp_2;
	t_list	*tmp_3;

	tmp_1 = data->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->lk_rooms;
		while (tmp_2)
		{
			tmp_3 = tmp_2;
			while (tmp_3->next)
			{
				if (!ft_strcmp(((t_room*)tmp_2->content)->name,
				((t_room*)tmp_3->next->content)->name))
					failure();
				tmp_3 = tmp_3->next;
			}
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
}

static void	add_links(t_room *stock_1, t_room *stock_2)
{
	t_list	*new_1;
	t_list	*new_2;

	if (!stock_1 || !stock_2)
		failure();
	if (!(new_1 = ft_lstnew(NULL, 0)))
		failure();
	if (!(new_2 = ft_lstnew(NULL, 0)))
		failure();
	new_1->content = (void*)stock_1;
	new_2->content = (void*)stock_2;
	if (stock_1->lk_rooms)
		new_2->next = stock_1->lk_rooms;
	stock_1->lk_rooms = new_2;
	if (stock_2->lk_rooms)
		new_1->next = stock_2->lk_rooms;
	stock_2->lk_rooms = new_1;
}

static void	get_links(t_lemin *data, char **tab)
{
	t_room	*tmp;
	t_room	*stock_1;
	t_room	*stock_2;

	stock_1 = NULL;
	stock_2 = NULL;
	tmp = data->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tab[0], tmp->name))
			stock_1 = tmp;
		tmp = tmp->next;
	}
	tmp = data->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tab[1], tmp->name))
			stock_2 = tmp;
		tmp = tmp->next;
	}
	add_links(stock_1, stock_2);
}

void		check_links(t_lemin *data, t_list *tmp)
{
	char	**tab;

	while (tmp && (ft_count_word((char*)tmp->content, ' ') == 1 ||
	((char*)tmp->content)[0] == '#'))
	{
		if (!(((char*)tmp->content)[0] == '#'))
		{
			if (!(ft_count_word((char*)tmp->content, '-') == 2))
				failure();
			if (!(tab = ft_strsplit((char*)tmp->content, '-')))
				failure();
			get_links(data, tab);
			tab_del(tab);
			free(tab);
		}
		tmp = tmp->next;
	}
	if (tmp)
		failure();
	check_double(data);
}

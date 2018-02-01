/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 03:15:47 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 10:15:08 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*get_ants(t_lemin *data)
{
	char		*str;

	str = (char*)data->params->content;
	if (ft_count_word(str, ' ') == 1 && is_int(str))
		data->ants = ft_atoi(str);
	else
		failure();
	if (data->params->next)
		return (data->params->next);
	return (NULL);
}

void			parser(t_lemin *data)
{
	char		*line;
	t_list		*tmp;
	int			ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
			failure();
		tmp->content = (void*)line;
		if (data->params)
			ft_lstadd_back(data->params, tmp);
		else
			data->params = tmp;
	}
	if (ret == -1)
		failure();
	if (!(tmp = get_ants(data)))
		failure();
	tmp = check_rooms(data, tmp);
	check_links(data, tmp);
	if (!data->end || !data->start || !data->ants)
		failure();
}

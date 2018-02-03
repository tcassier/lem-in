/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 03:16:04 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/03 18:49:51 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_len(t_lemin *data)
{
	int		index;

	index = 0;
	while (data->path[index] != NULL)
		index++;
	return (index);
}

static int	check_end(t_lemin *data)
{
	int		index;

	index = 1;
	while (data->path[index + 1])
	{
		if (data->path[index]->content_size != (size_t)-1)
			return (0);
		index++;
	}
	return (1);
}

static void	print_ants(t_lemin *data, int len)
{
	int		index;

	index = 1;
	while (index < len)
	{
		if (data->path[index]->content_size > 0 &&
		data->path[index]->content_size != (size_t)-1)
			ft_printf("L%zu-%s ", data->path[index]->content_size,
			((t_room*)data->path[index]->content)->name);
		index++;
	}
	ft_printf("\n");
}

static void	compute_ants(t_lemin *data, int len)
{
	int		index;

	while (!check_end(data))
	{
		index = len - 1;
		while (index > 0)
		{
			if (data->path[index]->content_size <
			data->path[index - 1]->content_size &&
			data->path[index - 1]->content_size != (size_t)-1 &&
			data->path[index]->content_size != (size_t)-1)
				data->path[index]->content_size++;
			if (index != len - 1 && data->path[index]->content_size != 0
			&& data->path[index]->content_size ==
			data->path[index + 1]->content_size)
				data->path[index]->content_size = (size_t)-1;
			index--;
		}
		print_ants(data, len);
	}
}

void		process(t_lemin *data)
{
	int		len;

	len = get_len(data);
	while (data->params)
	{
		ft_printf("%s\n", (char*)data->params->content);
		data->params = data->params->next;
	}
	ft_printf("\n");
	data->path[0]->content_size = (size_t)data->ants;
	compute_ants(data, len);
}

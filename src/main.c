/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:55:07 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/04 12:31:38 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_lemin	*data;

	if (!(data = (t_lemin*)ft_memalloc(sizeof(t_lemin))))
		return (EXIT_FAILURE);
	parser(data);
	get_path(data);
	process(data);
	return (EXIT_SUCCESS);
}

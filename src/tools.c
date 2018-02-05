/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 07:40:37 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/05 14:17:55 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	tab_del(char **tab)
{
	int	index;

	index = -1;
	while (tab[++index])
		free(tab[index]);
}

int		is_int(char *str)
{
	int	index;

	index = -1;
	if (str[0] == '-')
		index++;
	while (str[++index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
	}
	if (index > 2 && ft_atoi_sec(str) == -1)
		return (0);
	return (1);
}

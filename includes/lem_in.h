/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:49:00 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 08:53:24 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct		s_room
{
	char			*name;
	t_list			*lk_rooms;
	struct s_room	*next;
}					t_room;

typedef struct		s_lemin
{
	t_list			*params;
	t_room			*rooms;
	char			*start;
	char			*end;
	int				ants;
}					t_lemin;

void				check_links(t_lemin *data, t_list *tmp);
t_list				*check_rooms(t_lemin *data, t_list *tmp);
void				failure();
int					is_int(char *str);
void				parser(t_lemin *data);
void				tab_del(char **tab);
#endif

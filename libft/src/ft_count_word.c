/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 09:58:45 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 05:43:55 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_count_word(char const *s, char c)
{
	int		count;
	int		begin_word;

	begin_word = 0;
	count = 0;
	while (*s != '\0')
	{
		if (begin_word == 1 && *s == c)
			begin_word = 0;
		if (begin_word == 0 && *s != c)
		{
			begin_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

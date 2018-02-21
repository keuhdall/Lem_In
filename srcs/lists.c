/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:55:51 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/21 20:21:48 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room_list	*new_neighbor(t_room *room)
{
	t_room_list	*tmp;

	if (!(tmp = (t_room_list *)malloc(sizeof(t_room_list))))
		return (NULL);
	tmp->content = room->content;
	tmp->next = NULL;
	return (tmp);
}

void		push_neighbor(t_env *env, char *name, t_room_list *new)
{
	int			count;
	t_room_list	*tmp;

	count = -1;
	tmp = NULL;
	while (++count < env->rooms_length)
	{
		if (!ft_strcmp(env->rooms[count].content.name, name))
		{
			tmp = env->rooms[count].neighbors;
			if (!tmp)
				env->rooms[count].neighbors = new;
			else
			{
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = new;
			}
		}
	}
}

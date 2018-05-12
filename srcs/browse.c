/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:25:28 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/12 23:56:16 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	clear_visited(t_env *env)
{
	t_room_list	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		tmp->visited = 0;
		tmp = tmp->next;
	}
}

int		get_parent(t_room_list *parent, t_room_list *child)
{
	int	count;

	count = -1;
	parent->visited = 1;
	while (++count < parent->neighbors_size)
	{
		if (parent->neighbors[count] == child)
		{
			child->parent = parent;
			return (1);
		}
	}
	count = -1;
	while (++count < parent->neighbors_size)
	{
		if (!parent->neighbors[count]->visited)
		{
			if (get_parent(parent->neighbors[count], child))
				return (1);
		}
	}
	return (0);
}

void	set_parents(t_env *env)
{
	t_room_list	*tmp;

	tmp = env->start;
	while (tmp)
	{
		if (tmp == env->start)
			tmp->parent = NULL;
		else
			get_parent(env->start, tmp);
		clear_visited(env);
		tmp = tmp->next;
	}
}

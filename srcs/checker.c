/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:25:53 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/08 19:45:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
/*
int		check_path_to_end(t_env *env, t_room_list *curr)
{
	int	count;

	count = -1;
	curr->visited = 1;
	if (curr == env->end)
		return (1);
	while (++count < curr->neighbors_size)
	{
		if (!curr->neighbors[count]->visited)
		{
			if (check_path_to_end(env, curr->neighbors[count]))
				return (1);
		}
	}
	return (0);
}
*/

t_room_list	*get_parent(t_room_list *child)
{
	t_room_list	*tmp;

	tmp = tmp->start;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
}

int		check_path_to_end(t_env *env, t_room_list *curr)
{
	int	count;

	count = -1;
	curr->visited = 1;
	if (curr == env->end)
		return (1);
	while (++count < curr->neighbors_size)
	{
		if (!curr->neighbors[count]->visited)
		{
			if (check_path_to_end(env, curr->neighbors[count]))
				return (1);
		}
	}
	return (0);
}

void	check_env(t_env *env)
{
	if (!env->start || !env->end || !env->rooms || !env->ants_length)
		puterr(ERR_INVALID_STRUCT);
}

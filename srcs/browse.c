/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:25:28 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/01 23:48:19 by lmarques         ###   ########.fr       */
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

void	del_room_from_path(t_room_list **rooms, t_room_list *elt)
{
	t_room_list	*tmp;
	t_room_list	*tmp2;

	tmp = *rooms;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp == elt)
		{
			tmp2->next = tmp->next;
			free(tmp);
		}
	}
}

int		dfs(t_env *env, t_room_list *curr)
{
	int	count;

	count = -1;
	curr->visited = 1;
	push_room(&env->path, curr);
	if (curr == env->end)
	{
		env->lock_path = 1;
		return (1);
	}
	while (++count < curr->neighbors_size)
	{
		if (!curr->neighbors[count]->visited)
		{
			if (dfs(env, curr->neighbors[count]))
				return (1);
		}
	}
	if (!env->lock_path)
		del_room_from_path(&env->path, curr);
	return (0);
}


/*
void	dfs(t_env *env, t_room_list *curr)
{
	int	count;

	count = -1;
	curr->visited = 1;
	while (++count < curr->neighbors_size)
	{
		if (!curr->neighbors[count]->visited)
			dfs(env, curr->neighbors[count]);
	}
}*/

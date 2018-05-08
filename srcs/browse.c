/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:25:28 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/08 18:42:33 by lmarques         ###   ########.fr       */
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
}

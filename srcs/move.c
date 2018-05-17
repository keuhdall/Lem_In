/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 05:13:11 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/17 20:34:05 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

int			get_farest_ant(t_env *env)
{
	int	count;

	count = -1;
	while (++count < env->ants_size)
	{
		if (env->ants[count].room != env->end)
			return (count);
	}
	return (-1);
}

int			get_how_far_in_path(t_env *env, t_ant ant)
{
	int	count;

	count = -1;
	while (++count < env->path_size)
	{
		if (env->path[count] == ant.room)
			return (count);
	}
	return (-1);
}

t_room_list	*get_next_room(t_env *env, t_ant ant)
{
	int	count;

	count = -1;
	while (++count < env->path_size)
		if (ant.room == env->path[count])
			return (env->path[count + 1]);
	return (NULL);
}

void		move_ants(t_env *env, int count_ants)
{
	int	count;
	int	farest;

	count = -1;
	farest = get_farest_ant(env);
	while (++count < count_ants + 1)
	{
		if (farest + count < env->ants_size)
		{
			printf("Moving ant #%d from %s to %s\n",
			farest + count, env->ants[farest + count].room->name,
				get_next_room(env, env->ants[farest + count])->name);
			env->ants[farest + count].room = get_next_room(env,
				env->ants[farest + count]);
		}
	}
}

void		move_all_ants(t_env *env)
{
	while (get_farest_ant(env) != -1)
	{
		move_ants(env,
			get_how_far_in_path(env, env->ants[get_farest_ant(env)]));
		printf("==========================================\n");
	}
}

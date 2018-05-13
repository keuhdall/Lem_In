/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:40:00 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/13 05:13:48 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	rev_path(t_env *env)
{
	int			count;
	t_room_list	*tmp;

	count = -1;
	while (++count < env->path_size / 2)
	{
		tmp = env->path[count];
		env->path[count] = env->path[env->path_size - count - 1];
		env->path[env->path_size - count - 1] = tmp;
	}
}

void	set_path(t_env *env)
{
	t_room_list	*tmp;

	tmp = env->end;
	while (tmp)
	{
		++env->path_size;
		env->path = ft_realloc(env->path, sizeof(t_room_list) * env->path_size);
		env->path[env->path_size - 1] = tmp;
		tmp = tmp->parent;
	}
	rev_path(env);
}

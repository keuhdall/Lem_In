/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:15:40 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/21 15:06:27 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room	*find_room(t_env *env, char *name)
{
	int	count;

	count = -1;
	while (++count < env->rooms_length)
	{
		if (!ft_strcmp(env->rooms[count].content.name, name))
			return (&env->rooms[count]);
	}
	return (NULL);
}

void	add_neighbor(t_env *env, char *room1_name, char *room2_name)
{
	t_room	*room1;
	t_room	*room2;
	int		count;

	room1 = NULL;
	room2 = NULL;
	count = -1;
	if (!(room1 = find_room(env, room1_name)) ||
		!(room2 = find_room(env, room2_name)))
		puterr(ERR_ROOM_NOT_FOUND);
	push_neighbor(env, room1_name, new_neighbor(room2));
	push_neighbor(env, room2_name, new_neighbor(room1));
}

void	push_room(t_env *env, char *ln)
{
	char	**a;
	t_room	room;

	a = ft_strsplit(ln, ' ');
	room.content.name = ft_strdup(a[0]);
	room.content.pos.x = ft_atoi(a[1]);
	room.content.pos.y = ft_atoi(a[2]);
	room.neighbors = NULL;
	env->rooms[env->curr_room] = room;
	env->curr_room++;
	free_split(a);
}

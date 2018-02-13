/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:15:40 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/13 18:31:44 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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

	count = -1;
	if (!(room1 = find_room(env, room1_name)) ||
		!(room2 = find_room(env, room2_name)))
		puterr(ERR_ROOM_NOT_FOUND);
	push_neighbor(env, room1_name, new_neighbor(room2));
	push_neighbor(env, room2_name, new_neighbor(room1));
}

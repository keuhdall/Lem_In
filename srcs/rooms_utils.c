/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:15:40 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/12 19:54:35 by lmarques         ###   ########.fr       */
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

	if (!(room1 = find_room(env, room1_name)) ||
		!(room2 = find_room(env, room2_name)))
		puterr(ERR_ROOM_NOT_FOUND);
	//TODO: finish
}

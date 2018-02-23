/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:15:40 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/23 01:34:37 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

t_room_list	*new_room(char *ln)
{
	char		**a;
	t_room_list	*tmp;

	if (!(tmp = (t_room_list *)malloc(sizeof(t_room_list))))
		return (NULL);
	a = ft_strsplit(ln, ' ');
	tmp->name = ft_strdup(a[0]);
	tmp->pos.x = ft_atoi(a[1]);
	tmp->pos.y = ft_atoi(a[2]);
	tmp->neighbors = NULL;
	tmp->next = NULL;
	free_split(a);
	return (tmp);
}

void		push_room(t_room_list **rooms, t_room_list *new)
{
	t_room_list	*tmp;

	tmp = *rooms;
	if (!tmp)
		*rooms = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_room_list	*find_room(t_room_list *rooms, char *name)
{
	t_room_list	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		push_neighbor(t_room_list *rooms, char *name, t_room_list *new)
{
	t_room_list	*tmp_rooms;
	t_room_list	*tmp_neighbors;

	tmp_rooms = rooms;
	tmp_neighbors = NULL;
	while (tmp_rooms)
	{
		if (!ft_strcmp(tmp_rooms->name, name))
		{
			tmp_neighbors = *(&tmp_rooms->neighbors);
			if (!tmp_neighbors)
			{
				tmp_neighbors->neighbors = new;
				return ;
			}
			else
			{
				while (tmp_neighbors->next)
					tmp_neighbors = tmp_neighbors->next;
				tmp_neighbors->next = new;
				return ;
			}
		}
		tmp_rooms = tmp_rooms->next;
	}
}

void	add_neighbor(t_env *env, char *room1_name, char *room2_name)
{
	t_room_list	*room1;
	t_room_list	*room2;
	int		count;

	room1 = NULL;
	room2 = NULL;
	count = -1;
	if (!(room1 = find_room(env->rooms, room1_name)) ||
		!(room2 = find_room(env->rooms, room2_name)))
		puterr(ERR_ROOM_NOT_FOUND);
	push_neighbor(env->rooms, room1_name, room2);
	push_neighbor(env->rooms, room2_name, room1);
}

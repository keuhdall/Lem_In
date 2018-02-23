/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/23 11:24:18 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

void	print_neighbors(t_room_list *room)
{
	printf("Neighbors : \n");
	for (int i = 0; i < room->neighbors_size; i++)
	{
		printf("%s %d %d\n", room->neighbors[i]->name, room->neighbors[i]->pos.x, room->neighbors[i]->pos.y);
	}
}

int		main(int argc, char *argv[])
{
	t_env env;

	ft_bzero(&env, sizeof(env));
	if (argc != 2)
		puterr(ERR_WRONG_ARGS);
	init_structs(argv[1], &env);
	read_file(argv[1], &env);
	check_env(&env);
	fill_ants(&env);
	t_room_list	*tmp;
	tmp = *(&env.rooms);
	while (tmp)
	{
		printf("Name : %s posX : %d posY: %d\n", tmp->name, tmp->pos.x, tmp->pos.y);
		print_neighbors(tmp);
		printf("================\n");
		tmp = tmp->next;
	}
	for (int i = 0; i < env.ants_length; i++) {
		printf("ant ID : %d is in room : %s\n", env.ants[i].id, env.ants[i].room->name);
	}
	return (0);
}

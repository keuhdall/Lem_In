/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/22 18:30:16 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

void	print_neighbors(t_room *room)
{
	t_room_list	*rl;

	rl = NULL;
	rl = room->neighbors;
	printf("Neighbors : \n");
	while (rl)
	{
		printf("%s %d %d\n", rl->content.name, rl->content.pos.x, rl->content.pos.y);
		rl = rl->next;
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
	for (int i = 0; i < env.rooms_length; i++) {
		printf("Name : %s\n posX : %d posY: %d\n", env.rooms[i].content.name, env.rooms[i].content.pos.x, env.rooms[i].content.pos.y);
		print_neighbors(&env.rooms[i]);
		printf("================\n");
	}
	for (int i = 0; i < env.ants_length; i++) {
		printf("ant ID : %d is in room : %s\n", env.ants[i].id, env.ants[i].room.content.name);
	}
	return (0);
}

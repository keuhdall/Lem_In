/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/21 15:16:29 by lmarques         ###   ########.fr       */
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
		printf("%s\n", rl->content.name);
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
	for (int i = 0; i < env.rooms_length; i++) {
		printf("%s\n", env.rooms[i].content.name);
		print_neighbors(&env.rooms[i]);
		printf("================\n");
	}
	return (0);
}

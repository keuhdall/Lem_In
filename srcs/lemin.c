/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/02 00:00:25 by lmarques         ###   ########.fr       */
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

void	print_path(t_room_list *path)
{
	t_room_list	*tmp;

	tmp = path;
	while (tmp)
	{
		printf("Name : %s posX : %d posY: %d\n", tmp->name, tmp->pos.x, tmp->pos.y);
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
	printf("Start is : %s\n", env.start->name);
	printf("End is : %s\n", env.end->name);
	if (check_path_to_end(&env, env.start))
		printf("This map is valid !\n");
	else
		printf("This map is not valid !\n");
	dfs(&env, env.start);
	print_path(env.path);
	return (0);
}

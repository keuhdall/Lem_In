/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:25:53 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/20 02:52:23 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_path_to_end(t_env *env, t_room_list *curr)
{
	int	count;

	count = -1;
	curr->visited = 1;
	if (curr == env->end)
		return (1);
	while (++count < curr->neighbors_size)
	{
		if (!curr->neighbors[count]->visited)
		{
			if (check_path_to_end(env, curr->neighbors[count]))
				return (1);
		}
	}
	return (0);
}

void	assign_command(t_env *env, t_room_list *room)
{
	if (env->command == START)
	{
		if (!env->start)
			env->start = room;
		else
			puterr(ERR_COMMAND_ASSIGNED);
	}
	else if (env->command == END)
	{
		if (!env->end)
			env->end = room;
		else
			puterr(ERR_COMMAND_ASSIGNED);
	}
}

void	check_room_duplicate(t_env *env, t_room_list *room)
{
	t_room_list	*tmp;

	tmp = env->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, room->name))
			puterr(ERR_ROOM_DUPLICATE);
		tmp = tmp->next;
	}
}

void	check_args(t_env *env, int argc, char *argv[])
{
	if (argc < 2)
		return ;
	if (!ft_strcmp(argv[1], "-v"))
		env->options.verbose = 1;
	else if (!ft_strcmp(argv[1], "-f") ||
		!ft_strcmp(argv[1], "-vf") || !ft_strcmp(argv[1], "-fv"))
	{
		if (!ft_strcmp(argv[1], "-vf") || !ft_strcmp(argv[1], "-fv"))
			env->options.verbose = 1;
		env->options.file = 1;
		if (argc < 3)
			puterr(ERR_NO_FILENAME);
		else
			env->options.filename = ft_strdup(argv[2]);
	}
}

int		check_room_name(char *name)
{
	int	count;

	count = -1;
	if (name[0] == '#' || name[0] == 'L')
		return (0);
	while (name[++count])
	{
		if (name[count] == '-')
			return (0);
	}
	return (1);
}

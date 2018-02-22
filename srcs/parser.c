/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:07:54 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/23 00:36:10 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	parse_command(t_env *env, char *ln)
{
	if (!ft_strcmp(ln, "##start"))
		env->command = START;
	else if (!ft_strcmp(ln, "##end"))
		env->command = END;
	else
		puterr(ERR_INVALID_COMMAND);
}

void	parse_tube(t_env *env, char *ln)
{
	char	**a;

	a = ft_strsplit(ln, '-');
	if (!find_room(env->rooms, a[0]) || !find_room(env->rooms, a[1]))
		puterr(ERR_ROOM_NOT_FOUND);
	add_neighbor(env, a[0], a[1]);
	free_split(a);
}

void	parse_line(t_env *env, char *ln)
{
	t_room_list *room;

	room = NULL;
	if (get_line_type(ln) == COMMAND)
		parse_command(env, ln);
	else if (get_line_type(ln) == TUBE)
		parse_tube(env, ln);
	else if (get_line_type(ln) == ROOM)
	{
		room = new_room(ln);
		if (env->command != NONE)
		{
			if (env->command == START)
				env->start = room;
			else if (env->command == END)
				env->end = room;
			env->command = NONE;
		}
		push_room(&env->rooms, room);
	}
}

void	read_file(char *name, t_env *env)
{
	int		fd;
	int		ret;
	char	*ln;

	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &ln)))
	{
		if (ret == -1)
			puterr(ERR_FILE_OPEN);
		if (ft_strcmp(ln, "") && get_line_type(ln) != COMMENT)
			parse_line(env, ln);
		free(ln);
	}
	free(ln);
	close(fd);
}

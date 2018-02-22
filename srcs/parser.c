/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:07:54 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/22 17:23:54 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	parse_line(t_env *env, char *ln)
{
	if (get_line_type(ln) == COMMAND)
		parse_command(env, ln);
	else if (get_line_type(ln) == TUBE)
		parse_tube(env, ln);
	else if (get_line_type(ln) == ROOM)
	{
		if (env->command != NONE)
		{
			if (env->command == START)
				env->start = create_room(ln);
			else if (env->command == END)
				env->end = create_room(ln);
			env->command = NONE;
		}
		push_room(env, ln);
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

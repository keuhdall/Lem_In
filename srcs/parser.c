/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:07:54 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/20 19:14:54 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	parse_line(t_env *env, char *ln)
{
	if (get_line_type(ln) == COMMENT)
		ft_putendl("It's a comment !");
	if (get_line_type(ln) == COMMAND)
	{
		ft_putendl("parse_command 1");
		parse_command(env, ln);
		ft_putendl("parse_command 2");
	}
	env->command = NONE;
	if (get_line_type(ln) == TUBE)
	{
		ft_putendl("parse_tube 1");
		parse_tube(env, ln);
		ft_putendl("parse_tube 2");
	}
	if (get_line_type(ln) == ROOM)
		ft_putendl("It's a room !");
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
		//if (ft_strcmp(ln, "") && get_line_type(ln) != COMMENT)
		//	parse_line(env, ln);
		if (ft_strcmp(ln, ""))
			parse_line(env, ln);
		free(ln);
	}
	free(ln);
	close(fd);
}

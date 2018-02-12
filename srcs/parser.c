/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:07:54 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/12 18:50:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	parse_command(t_env *env, char *ln)
{
	if (!ft_strcmp(ln, "##start"))
		env->command = START;
	else if (!ft_strcmp(ln, "##end"))
		env->command = END;
	else
		puterr(ERR_INVALID_COMMAND);
}

void	parse_line(t_env *env, char *ln)
{
	if (get_line_type(ln) == COMMAND)
		parse_command(env, ln);
	env->command = NONE;
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
}

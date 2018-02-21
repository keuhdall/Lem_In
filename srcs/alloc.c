/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/21 14:13:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	update_struct_size(t_env *env, char *ln)
{
	if (get_line_type(ln) == ANT)
		env->ants_length++;
	else if (get_line_type(ln) == ROOM)
		env->rooms_length++;
}

void	alloc_arrays(t_env *env)
{
	if (!((t_room *)malloc(sizeof(t_room) * env->rooms_length)))
		puterr(ERR_MALLOC_FAILED);
	if (!((t_ant *)malloc(sizeof(t_ant) * env->ants_length)))
		puterr(ERR_MALLOC_FAILED);
}

void	init_structs(char *name, t_env *env)
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
			update_struct_size(env, ln);
		free(ln);
	}
	free(ln);
	close(fd);
	alloc_arrays(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/21 20:21:27 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	alloc_arrays(t_env *env)
{
	if (!(env->rooms = (t_room *)malloc(sizeof(t_room) * env->rooms_length)))
		puterr(ERR_MALLOC_FAILED);
	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->ants_length)))
		puterr(ERR_MALLOC_FAILED);
}

void	init_structs(char *name, t_env *env)
{
	int		fd;
	int		ret;
	char	*ln;

	fd = open(name, O_RDONLY);
	if ((ret = get_next_line(fd, &ln)) == -1)
		puterr(ERR_FILE_OPEN);
	else if (!ft_isstrdigit(ln))
		puterr(ERR_INVALID_SYNTAX);
	else
		env->ants_length = ft_atoi(ln);
	free(ln);
	while ((ret = get_next_line(fd, &ln)))
	{
		if (ret == -1)
			puterr(ERR_FILE_OPEN);
		if (ft_strcmp(ln, "") && get_line_type(ln) == ROOM)
			env->rooms_length++;
		free(ln);
	}
	free(ln);
	close(fd);
	alloc_arrays(env);
}

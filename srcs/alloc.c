/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/11 03:49:02 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	fill_ants(t_env *env)
{
	int		count;
	t_ant	ant;

	count = -1;
	while (++count < env->ants_length)
	{
		ant.id = count;
		ant.room = env->start;
		env->ants[count] = ant;
	}
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
	close(fd);
	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->ants_length)))
		puterr(ERR_MALLOC_FAILED);
	env->path = NULL;
}

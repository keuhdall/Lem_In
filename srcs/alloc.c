/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/18 19:45:59 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	fill_ants(t_env *env)
{
	int		count;
	t_ant	ant;

	count = -1;
	while (++count < env->ants_size)
	{
		ant.id = count;
		ant.room = env->start;
		env->ants[count] = ant;
	}
}

void	init_structs(t_env *env, char *name)
{
	int		fd;
	int		ret;
	char	*ln;

	fd = env->options.file ?  open(name, O_RDONLY) : 0;
	if ((ret = get_next_line(fd, &ln)) == -1)
		puterr(ERR_FILE_OPEN);
	else if (!ft_isstrdigit(ln))
		puterr(ERR_INVALID_SYNTAX);
	else
		env->ants_size = ft_atoi(ln);
	free(ln);
	if (env->options.file)
		close(fd);
	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->ants_size)))
		puterr(ERR_MALLOC_FAILED);
	env->path = NULL;
}

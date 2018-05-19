/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/19 19:50:59 by lmarques         ###   ########.fr       */
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
	int		ret;
	char	*ln;

	env->fd = env->options.file ? open(name, O_RDONLY) : 0;
	while ((ret = get_next_line(env->fd, &ln) && get_line_type(ln) == COMMENT))
	{
		if (ret == -1)
			puterr(ERR_FILE_OPEN);
		ft_lst_push_back(&env->map, ft_lstnew(ln, ft_strlen(ln) + 1));
		free(ln);
	}
	if (!ft_isstrdigit(ln))
		puterr(ERR_INVALID_SYNTAX);
	else
	{
		ft_lst_push_back(&env->map, ft_lstnew(ln, ft_strlen(ln) + 1));
		env->ants_size = ft_atoi(ln);
		if (env->ants_size <= 0)
			puterr(ERR_INVALID_SYNTAX);
	}
	free(ln);
	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->ants_size)))
		puterr(ERR_MALLOC_FAILED);
}

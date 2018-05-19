/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:25:53 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/19 17:55:24 by lmarques         ###   ########.fr       */
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

void	check_env(t_env *env)
{
	if (!env->start || !env->end || !env->rooms || !env->ants_size)
		puterr(ERR_INVALID_STRUCT);
}

void	register_filename(t_env *env, int argc, char *argv[])
{
	env->options.file = 1;
	if (argc < 3)
		puterr(ERR_NO_FILENAME);
	else
		env->options.filename = ft_strdup(argv[2]);
}

void	check_args(t_env *env, int argc, char *argv[])
{
	if (argc < 2)
		return ;
	if (!ft_strcmp(argv[1], "-v"))
		env->options.verbose = 1;
	else if (!ft_strcmp(argv[1], "-f"))
		register_filename(env, argc, argv);
	else if (!ft_strcmp(argv[1], "-vf") || !ft_strcmp(argv[1], "-fv"))
	{
		env->options.verbose = 1;
		register_filename(env, argc, argv);
	}
}

int		check_room_name(char *name)
{
	int	count;

	count = -1;
	while (name[++count])
	{
		if (name[count] == '-')
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/18 04:46:17 by lmarques         ###   ########.fr       */
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

void	init_structs_file(t_env *env, char *name)
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
		env->ants_size = ft_atoi(ln);
	free(ln);
	close(fd);
	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->ants_size)))
		puterr(ERR_MALLOC_FAILED);
	env->path = NULL;
}

void	init_structs_args(t_env *env, int argc, char *argv[])
{
	int	req_args;

	req_args = env->options.verbose ? 3 : 2;
	if (argc < req_args)
		puterr(ERR_INVALID_STRUCT);
	else
	{
		if (!ft_isstrdigit(argv[req_args - 1]))
			puterr(ERR_INVALID_SYNTAX);
		else
			env->ants_size = ft_atoi(argv[req_args - 1]);
	}
	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->ants_size)))
		puterr(ERR_MALLOC_FAILED);
	env->path = NULL;
}

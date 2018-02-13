/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:09:09 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/13 18:42:40 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	parse_command(t_env *env, char *ln)
{
	if (!ft_strcmp(ln, "##start"))
		env->command = START;
	else if (!ft_strcmp(ln, "##end"))
		env->command = END;
	else
		puterr(ERR_INVALID_COMMAND);
}

void	parse_tube(t_env *env, char *ln)
{
	char	**a;

	a = ft_strsplit(ln, '-');
	if (!find_room(env, a[0]) || !find_room(env, a[1]))
		puterr(ERR_ROOM_NOT_FOUND);
	add_neighbor(env, a[0], a[1]);
}

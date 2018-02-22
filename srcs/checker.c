/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:25:53 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/22 17:32:41 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_path_to_end(t_env *env)
{
	return (env ? 1 : 0);
}

void	check_env(t_env *env)
{
	if (!env->start.content.name || !env->end.content.name ||
			!env->rooms_length || !env->ants_length)
		puterr(ERR_INVALID_STRUCT);
}
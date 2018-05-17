/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:02:00 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/17 23:41:08 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	default_print(t_env *env, int farest, int count)
{
	ft_printf("L%d-%s ", farest + count,
		get_next_room(env, env->ants[farest + count])->name);
}

void	verbose_print(t_env *env, int farest, int count)
{
	ft_printf("Moving ant #%d from %s to %s\n",
		farest + count, env->ants[farest + count].room->name,
		get_next_room(env, env->ants[farest + count])->name);
}

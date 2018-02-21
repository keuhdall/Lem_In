/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/21 14:31:02 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	main(int argc, char *argv[])
{
	t_env env;

	ft_bzero(&env, sizeof(env));
	if (argc != 2)
		puterr(ERR_WRONG_ARGS);
	init_structs(argv[1], &env);
	read_file(argv[1], &env);
	for (int i = 0; i < env.rooms_length; i++) {
		ft_putendl(env.rooms[i].content.name);
	}
	return (0);
}

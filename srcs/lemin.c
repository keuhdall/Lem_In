/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/18 19:47:08 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		main(int argc, char *argv[])
{
	t_env env;

	ft_bzero(&env, sizeof(env));
	check_args(&env, argc, argv);
	init_structs(&env, env.options.filename);
	read_file(&env, env.options.filename);
	check_env(&env);
	fill_ants(&env);
	if (!check_path_to_end(&env, env.start))
		puterr(ERR_NO_PATH);
	clear_visited(&env);
	set_parents(&env);
	set_path(&env);
	move_all_ants(&env);
	return (0);
}

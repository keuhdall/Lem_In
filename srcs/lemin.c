/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:55:10 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/20 19:08:41 by lmarques         ###   ########.fr       */
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
	ft_putendl("test");
	read_file(argv[1], &env);
	return (0);
}

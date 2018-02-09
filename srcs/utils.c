/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:10:15 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/09 18:21:17 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	puterr(int e)
{
	if (e == ERR_FILE_OPEN)
		ft_putendl("Error : could not open this file");
	exit(1);
}

int		is_comment(char *s)
{
	if (!s)
		return (0);
	if (ft_strlen(s) >= 2)
		return (s[0] == '#' && s[1] != '#');
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:10:15 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/10 02:34:44 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	puterr(int e)
{
	if (e == ERR_FILE_OPEN)
		ft_putendl("Error : could not open this file");
	exit(1);
}

int		get_line_type(char *s)
{
	if (!s)
		return (-1);
	if (ft_strlen(s) >= 2)
	{
		if (s[0] == '#' && s[1] != '#')
			return (COMMENT);
		else if (s[0] == '#' && s[1] == '#')
			return (COMMAND);
	}
	return (COMMON);
}

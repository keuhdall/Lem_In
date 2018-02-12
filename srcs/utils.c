/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:10:15 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/12 18:50:20 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	puterr(int e)
{
	if (e == ERR_FILE_OPEN)
		ft_putendl_fd("Error : could not open this file", 2);
	else if (e == ERR_INVALID_COMMAND)
		ft_putendl_fd("Error : invalid command", 2);
	exit(1);
}

int		get_line_type(char *s)
{
	if (!s)
		return (-1);
	if (ft_strlen(s) >= 2 && s[0] == '#')
		return (s[1] == '#' ? COMMAND : COMMENT);
	else if (s[0] == 'L')
		return (ANT);
	return (COMMON);
}

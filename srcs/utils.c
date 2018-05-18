/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:10:15 by lmarques          #+#    #+#             */
/*   Updated: 2018/05/18 04:10:32 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	puterr(int e)
{
	if (e == ERR_WRONG_ARGS)
		ft_putendl_fd("Error : please provide only one argument", 2);
	else if (e == ERR_FILE_OPEN)
		ft_putendl_fd("Error : could not open this file", 2);
	else if (e == ERR_INVALID_COMMAND)
		ft_putendl_fd("Error : invalid command", 2);
	else if (e == ERR_INVALID_SYNTAX)
		ft_putendl_fd("Error : invalid syntax", 2);
	else if (e == ERR_INVALID_STRUCT)
		ft_putendl_fd("Error : invalid struct : you either don't \
have declared any start/end ; created any room / ant ; \
or didn't link your rooms correctly", 2);
	else if (e == ERR_ROOM_NOT_FOUND)
		ft_putendl_fd("Error : room not found", 2);
	else if (e == ERR_MALLOC_FAILED)
		ft_putendl_fd("Error : failed to allocate memory ; exitting", 2);
	else if (e == ERR_NO_PATH)
		ft_putendl_fd("Error : no path found", 2);
	else if (e == ERR_NO_FILENAME)
		ft_putendl_fd("Error : -f option is given, but no filename is provided",
			2);
	exit(1);
}

void	free_split(char **a)
{
	int	count;

	count = -1;
	while (a[++count])
		free(a[count]);
	free(a);
}

int		get_array_length(char **a)
{
	int	count;

	count = -1;
	while (a[++count])
		continue ;
	return (count);
}

int		get_line_type(char *s)
{
	char **a;

	if (!s)
		return (-1);
	a = ft_strsplit(s, '-');
	if (ft_strlen(s) >= 2 && s[0] == '#')
	{
		free_split(a);
		return (s[1] == '#' ? COMMAND : COMMENT);
	}
	else if (get_array_length(a) == 2)
	{
		free_split(a);
		return (TUBE);
	}
	free_split(a);
	a = ft_strsplit(s, ' ');
	if (get_array_length(a) == 3 && ft_isstrdigit(a[1]) && ft_isstrdigit(a[2]))
	{
		free_split(a);
		return (ROOM);
	}
	free_split(a);
	return (COMMON);
}

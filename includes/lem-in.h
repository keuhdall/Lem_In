/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:53:42 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/10 02:29:49 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

enum	e_errors
{
	ERR_FILE_OPEN
};

enum	e_line_type
{
	COMMAND,
	COMMENT,
	COMMON
};

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	char			*name;
	t_point			pos;
	struct s_room	*neighbors;
}					t_room;

typedef struct		s_env
{
	t_room			*rooms;
}					t_env;

void				puterr(int e);
int					get_line_type(char *s);

#endif

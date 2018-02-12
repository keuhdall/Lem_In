/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:53:42 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/12 18:49:47 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

enum	e_errors
{
	ERR_FILE_OPEN,
	ERR_INVALID_COMMAND
};

enum	e_line_type
{
	COMMAND,
	COMMENT,
	ANT,
	COMMON
};

enum	e_commands
{
	NONE,
	START,
	END
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

typedef struct		s_ant
{
	int				id;
	t_room			pos;
}					t_ant;

typedef struct		s_env
{
	int				command;
	t_room			*rooms;
	t_ant			*ants;
}					t_env;

void				puterr(int e);
int					get_line_type(char *s);

#endif

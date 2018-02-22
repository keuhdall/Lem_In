/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:53:42 by lmarques          #+#    #+#             */
/*   Updated: 2018/02/22 18:24:12 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

enum	e_errors
{
	ERR_WRONG_ARGS,
	ERR_FILE_OPEN,
	ERR_INVALID_COMMAND,
	ERR_INVALID_SYNTAX,
	ERR_INVALID_STRUCT,
	ERR_ROOM_NOT_FOUND,
	ERR_MALLOC_FAILED
};

enum	e_line_type
{
	COMMAND,
	ROOM,
	COMMENT,
	TUBE,
	COMMON
};

enum	e_commands
{
	NONE,
	START,
	END
};

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_room_content
{
	char				*name;
	t_point				pos;
	struct s_room		*neighbors;
}						t_room_content;

typedef struct			s_room_list
{
	t_room_content		content;
	struct s_room_list	*next;
}						t_room_list;

typedef struct			s_room
{
	t_room_content		content;
	t_room_list			*neighbors;
}						t_room;

typedef struct			s_ant
{
	int					id;
	t_room				room;
}						t_ant;

typedef struct			s_env
{
	int					command;
	int					curr_room;
	int					rooms_length;
	t_room				*rooms;
	t_room				start;
	t_room				end;
	int					curr_ant;
	int					ants_length;
	t_ant				*ants;
}						t_env;

void					puterr(int e);
void					free_split(char **a);
void					init_structs(char *name, t_env *env);
void					read_file(char *name, t_env *env);

int						get_line_type(char *s);
void					parse_command(t_env *env, char *ln);
void					parse_tube(t_env *env, char *ln);

t_room_list				*new_neighbor(t_room *room);
void					push_neighbor(t_env *env, char *name, t_room_list *new);
void					add_neighbor(t_env *env, char *room1_name,
							char *room2_name);

t_room					create_room(char *ln);
t_room					*find_room(t_env *env, char *ln);
void					push_room(t_env *env, char *ln);

void					check_env(t_env *env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:53:42 by lmarques          #+#    #+#             */
/*   Updated: 2018/03/01 23:54:32 by lmarques         ###   ########.fr       */
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

typedef struct			s_room_list
{
	char				*name;
	t_point				pos;
	char				visited;
	int					neighbors_size;
	struct s_room_list	**neighbors;
	struct s_room_list	*next;
}						t_room_list;

typedef struct			s_ant
{
	int					id;
	t_room_list			*room;
}						t_ant;

typedef struct			s_env
{
	int					command;
	int					curr_room;
	t_room_list			*rooms;
	t_room_list			*start;
	t_room_list			*end;
	int					curr_ant;
	int					ants_length;
	t_ant				*ants;
}						t_env;

void					puterr(int e);
int						get_array_length(char **a);
void					free_split(char **a);
int						get_line_type(char *s);
void					read_file(char *name, t_env *env);

void					init_structs(char *name, t_env *env);
void					fill_ants(t_env *env);

t_room_list				*new_room(char *ln);
void					push_room(t_room_list **rooms, t_room_list *new);
t_room_list				*find_room(t_room_list *rooms, char *ln);
void					add_neighbor(t_env *env, char *room1_name,
							char *room2_name);

void					check_env(t_env *env);
int						check_path_to_end(t_env *env, t_room_list *curr);

void					clear_visited(t_env *env);

#endif

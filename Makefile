#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/19 05:25:46 by lmarques          #+#    #+#             *#
#*   Updated: 2018/05/13 05:14:14 by lmarques         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=lem-in

SRC_PATH=./srcs
INC_PATH=./includes
OBJ_PATH=./objs
LIBFT_PATH=./libft
PRINTF_PATH=./libft/ft_printf

SRC_NAME = lemin.c \
			alloc.c \
			browse.c \
			checker.c \
			move.c \
			parser.c \
			path.c \
			print.c \
			rooms_utils.c \
			utils.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc -g
CFLAGS = -Werror -Wextra -Wall

SRC=$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C $(PRINTF_PATH)
	$(CC) $^ -o $@ -L$(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INC_PATH) -I$(LIBFT_PATH) -I $(PRINTF_PATH)

clean:
	rm -fv $(OBJ)
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		make -C $(LIBFT_PATH) clean
		make -C $(PRINTF_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	rm -fv $(NAME)

re:fclean all

.PHONY: all, clean, fclean, re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 11:02:25 by ldesnoye          #+#    #+#              #
#    Updated: 2022/07/06 16:27:14 by ldesnoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

RM			= rm -f
RD			= rm -fr

FILE_DIR	= srcs
INC_DIR		= inc
OBJ_DIR		= objs
LIBFT_DIR	= libft

FILE_NAMES	+= arg_check.c
FILE_NAMES	+= color_parser.c
FILE_NAMES	+= create_structs.c
FILE_NAMES	+= frame_handler.c
FILE_NAMES	+= free_structs.c
FILE_NAMES	+= get_next_line.c
FILE_NAMES	+= get_next_line_utils.c
FILE_NAMES	+= get_texture_pixel.c
FILE_NAMES	+= init_player_pos.c
FILE_NAMES	+= keypress.c
FILE_NAMES	+= map_checker.c
FILE_NAMES	+= map_checker_utils.c
FILE_NAMES	+= map_parsing.c
FILE_NAMES	+= open_textures.c
FILE_NAMES	+= path_finder.c
FILE_NAMES	+= projection.c
FILE_NAMES	+= projection_x.c
FILE_NAMES	+= projection_z.c
FILE_NAMES	+= reverser.c
FILE_NAMES	+= rots.c
FILE_NAMES	+= sprites.c
FILE_NAMES	+= steps.c
FILE_NAMES	+= test.c
FILE_NAMES	+= texture_checking.c
FILE_NAMES	+= texture_parsing.c
FILE_NAMES	+= vect_ops.c
FILE_NAMES	+= vect_rot.c

OBJ_NAMES	= ${FILE_NAMES:.c=.o}
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS 		+= -g
# CFLAGS	+= -g3 -fsanitize=address
# CFLAGS	+= -g3 -fsanitize=thread

MLX_FLAGS	= -L./mlx_linux -lmlx -lXext -lX11

LIBR		= ranlib

all:		${NAME}

$(NAME):	${OBJS} 
			@echo "\n\033[1;35mCreating lib ...\033[0m\n"
			@$(MAKE) -C ./libft > /dev/null
			@echo "\033[1;34mCompiling $(NAME)...\033[0m"
			@$(CC) $(CFLAGS) $(OBJS) -I./$(INC_DIR)/ -L./$(LIBFT_DIR)/ -lft -lm $(MLX_FLAGS) -o $(NAME)
			@echo "\n\033[1;93mAll done !\033[0m\n"

$(OBJ_DIR)/%.o :	$(FILE_DIR)/%.c ${INC_DIR}/cubstructures.h ${INC_DIR}/cubconsts.h | $(OBJ_DIR)
					@echo "\033[0;96mCompiling $<\033[0m"
					@$(CC) $(CFLAGS) -c $< -o $@ -I./$(INC_DIR)/

$(OBJ_DIR) :
				@mkdir -p $(OBJ_DIR)

clean:
			@echo "\033[0;31mDeleting objects ...\033[0m\n"
			@${RM} ${OBJS}
			@$(RD) $(OBJ_DIR)
			@echo "\033[0;31mCleaning libft ...\033[0m"
			@$(MAKE) clean -C ./libft/ > /dev/null
			@echo "\033[0;31mDone.\033[0m\n"

fclean:		clean
			@echo "\033[0;31mDeleting libraries and executable\033[0m"
			@${RM} ${NAME}
			@$(RM) ./minishell
			@$(MAKE) fclean -C ./libft/ > /dev/null
			@echo "\033[0;31mDone.\033[0m\n"

re:			fclean all

.PHONY: 	all clean fclean re

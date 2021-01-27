# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pravry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 15:26:28 by pravry            #+#    #+#              #
#    Updated: 2021/01/27 11:20:53 by pravry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g -Wall -Wextra -Werror

MAC =  -I ./includes -I ./includes/minilib

LIB = -L ./includes/minilib -lmlx_Linux -lXext -lX11 -lm

SRCS_DIR = srcs/

NAME = cub3D

SRCS = 		srcs/check_info.c\
			srcs/close_window.c\
			srcs/check_double.c\
			srcs/dda_utils.c\
			srcs/draw.c\
			srcs/exit_prog.c\
			srcs/free_i.c\
			srcs/free_struct.c\
			srcs/free_tab.c\
			srcs/ft_atoi.c\
			srcs/ft_calloc.c\
			srcs/ft_check.c\
			srcs/ft_check_map.c\
			srcs/ft_check_pos.c\
			srcs/ft_fill_info.c\
			srcs/ft_itoa.c\
			srcs/ft_move.c\
			srcs/ft_parse_map.c\
			srcs/ft_rotate.c\
			srcs/ft_setup.c\
			srcs/ft_setup_cam.c\
			srcs/ft_setup_game.c\
			srcs/ft_setup_game_utils.c\
			srcs/ft_split.c\
			srcs/ft_strcmp.c\
			srcs/ft_strjoinmap.c\
			srcs/ft_strlcpy.c\
			srcs/ft_strncmp.c\
			srcs/ft_swap.c\
			srcs/get_next_line.c\
			srcs/get_next_line_utils.c\
			srcs/hook_init.c\
			srcs/init_sprite.c\
			srcs/init_text.c\
			srcs/main.c\
			srcs/minilibx.c\
			srcs/parse_input.c\
			srcs/parse_map_utils.c\
			srcs/save.c\
			srcs/sprite2.c\
			srcs/sprite.c\
			srcs/trace.c\
			srcs/add_color.c\
			srcs/check_color.c\
			srcs/cub3.c\

HEADERS = cub3d.h

OBJECT = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(MAC) -c $< -o $@

$(NAME): $(OBJECT)
	@$(CC) $(MAC) $(OBJECT) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)
	

re : fclean all

.PHONY: re clean fclean 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 18:02:54 by dpadovan          #+#    #+#              #
#    Updated: 2021/10/27 22:38:51 by dpadovan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -O3

NAME	=	fractol

RM		=	rm -rf

SRC_DIR	=	./files/

OBJ_DIR	=	./objs/

LBX_DIR =	./minilibx-linux/libmlx_Linux.a

SRC		=	main.c \
			ft_julia.c \
			ft_mandelbrot.c \
			ft_burning_ship.c \
			ft_parse_and_check.c \
			ft_my_color_pixel.c \
			ft_coords_and_limits.c \
			ft_win_to_viewport.c \
			ft_init_render.c \
			ft_close_clean.c \
			ft_hooks.c \
			ft_zoom.c \
			ft_utils.c \

INCLUDE	=	-I ./minilibx-linux -I ./include

LIBX    =	-lmlx_Linux -L./minilibx-linux -lXext -lX11 -lm

OBJ		=	${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}

${OBJ_DIR}%.o:		${SRC_DIR}%.c
			mkdir -p ${OBJ_DIR}
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all:		${NAME}

${NAME}: 	${LBX_DIR} ${OBJ}
			${CC} ${CFLAGS} ${OBJ} ${LIBX} ${INCLUDE} -o ${NAME}

${LBX_DIR}:
			make all -C./minilibx-linux

clean:
			make clean -C./minilibx-linux
			${RM} ${OBJ_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
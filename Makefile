# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:08:33 by jlenna            #+#    #+#              #
#    Updated: 2022/06/28 15:50:03 by jlenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = $(SRC_GNL) so_long.c	checker.c checker_2.c draw.c \
		draw_window.c exit_game.c key_game.c

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix gnl/, $(GNL))
		
HEADER = so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -w
RM = rm -f

LIB = libft/libft.a
PRINTF = printf/libftprintf.a

OBJS = $(SRCS:%.c=%.o)

all:	libft printf $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS)  -c $< -o $@

libft: 
	make -C libft/

printf:
	make -C printf/

MLX	= -L mlx -lmlx -framework OpenGL -framework AppKit

$(NAME) : 	$(OBJS)
			make -s -C mlx
			@mv mlx/libmlx.dylib .
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(PRINTF) $(MLX) -o $(NAME)

clean :
	make -C libft/ clean
	make -C printf/ clean
	make -C mlx clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	
fclean : clean
	make -C libft/ fclean
	make -C printf/ fclean
	$(RM) libmlx.dylib
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all
	make re -C mlx

.PHONY : all clean fclean re libft printf bonus

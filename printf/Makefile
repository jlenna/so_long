# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 18:18:34 by jlenna            #+#    #+#              #
#    Updated: 2022/01/07 16:20:50 by jlenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c	ft_printf_utils.c	ft_itoa_calloc.c	ft_print_hex.c\
		  ft_print_unsigned.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
RM	= rm -f

HEADER	= ft_printf.h

FLAGS	= -Wall -Wextra -Werror 

all : $(NAME)

$(NAME):	$(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) *.o

fclean:	clean
		$(RM) $(NAME)

re : fclean all
.PHONY: all clean fclean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 16:33:26 by jlenna            #+#    #+#              #
#    Updated: 2022/06/23 14:32:41 by jlenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_isalpha.c	ft_isalnum.c ft_isdigit.c ft_isascii.c\
		  ft_isprint.c ft_strlen.c 	ft_strlcat.c ft_memset.c\
		  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
		  ft_toupper.c ft_tolower.c	ft_strchr.c ft_strrchr.c\
		  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
			ft_strtrim.c ft_split.c ft_itoa.c\
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS	= $(patsubst %.c, %.o, $(SRCS))

CC	= cc
RM	= rm -f

HEADER	= libft.h

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

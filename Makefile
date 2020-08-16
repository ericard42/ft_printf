# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard <ericard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 12:55:22 by ericard           #+#    #+#              #
#    Updated: 2020/08/16 19:42:08 by ericard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			srcs/ft_atoi.c \
			srcs/ft_putstr.c \
			srcs/ft_flags.c \
			srcs/ft_strlen.c \
			srcs/ft_integer.c \
			srcs/ft_pointer.c \
			srcs/ft_string.c \
			srcs/ft_type.c \
			srcs/ft_strdup.c \

INCLUDE	=	-I includes/

NAME	=	libftprintf.a

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

clean:	
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:

.PHONY: all clean fclean re bonus
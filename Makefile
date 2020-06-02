# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard <ericard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 12:55:22 by ericard           #+#    #+#              #
#    Updated: 2020/05/09 19:04:42 by ericard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			srcs/ft_atoi.c \
			srcs/ft_putchar.c \
			srcs/ft_putstr.c \

INCLUDE	=	includes/ft_printf.h

NAME	=	libftprintf.a

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			ar rcs $(NAME) $(OBJS)

clean:	
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:

.PHONY: all clean fclean re bonus
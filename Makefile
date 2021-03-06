# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard <ericard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 12:55:22 by ericard           #+#    #+#              #
#    Updated: 2021/01/28 16:21:28 by ericard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			srcs/ft_putstr.c \
			srcs/ft_flags.c \
			srcs/ft_strlen.c \
			srcs/ft_pointer.c \
			srcs/ft_string.c \
			srcs/ft_type.c \
			srcs/ft_strdup.c \
			srcs/ft_isdigit.c \
			srcs/ft_width.c \
			srcs/ft_decimal.c \
			srcs/ft_itoa.c \
			srcs/ft_itoa_base.c \
			srcs/ft_hexa.c \
			srcs/ft_unsigned.c \
			srcs/ft_itoa_u.c \

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
			@printf "\e[1A\e[0K"

clean:	
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re

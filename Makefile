# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemiroz <sdemiroz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 22:14:18 by sdemiroz          #+#    #+#              #
#    Updated: 2024/03/29 01:23:25 by sdemiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c fti_putchar.c fti_putstr.c ft_itoa.c \
			ft_strlen.c ft_sx.c ft_bx.c ft_ux.c ft_px.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
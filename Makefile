# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysavalen <ysavalen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 23:24:54 by ysavalen          #+#    #+#              #
#    Updated: 2024/12/08 23:48:10 by ysavalen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= ft_printf.h
AR			= ar rcs
RM			= rm -f

SRCS	=	ft_printf.c\
			ft_printf_utils.c\
			ft_printf_advanced_utils.c\

OBJS	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(AR) $(NAME) $(OBJS)

clean:
	@echo "Removing object files..."
	$(RM) $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

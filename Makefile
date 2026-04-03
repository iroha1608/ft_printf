# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsato <nsato@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 14:51:53 by nsato             #+#    #+#              #
#    Updated: 2025/12/01 18:53:36 by nsato            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
TARGET		= ft_printf

SRC_DIR		= ./srcs/
SRCS		= ft_printf.c \
			ft_format.c \
			ft_putfunc.c
SRC_MAIN	= .ft_printf_main.c
			
OBJ_DIR		=  ./objs/
OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_MAIN	= $(addprefix $(OBJ_DIR), $(SRC_MAIN:.c=.o))

HEADER_DIR	= ./hdrs/
HEADER_NAME	= ft_printf.h
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_NAME))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(HEADER_DIR)
MFLAGS		= -I$(HEADER_DIR)


all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(OBJ_DIR):
	mkdir -p $@


main: $(TARGET)

$(TARGET): $(OBJ_MAIN) $(NAME)
	$(CC) $(MFLAGS) -o $@ $^

$(OBJ_DIR)%.o: %.c  $(HEADER) | $(OBJ_DIR)
	$(CC) $(MFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME) $(TARGET)

re: fclean all

.PHONY: all clean fclean re main

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebard <jlebard@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 15:39:17 by jlebard            #+#    #+#              #
#    Updated: 2024/05/08 15:39:17 by jlebard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CLEAN = rm -rf
FCLEAN = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = free_and_errors.c ft_split.c main.c push_command.c push_swap.c \
reverse_rotate_command.c rotate_command.c set_nodes.c sort_mini.c stack_init.c \
stack_utils.c swap_command.c
OBJS = $(SRC:.c=.o)

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(CLEAN) *.o

fclean: clean
	$(FCLEAN) $(NAME)

re: fclean all

.PHONY: all clean fclean re
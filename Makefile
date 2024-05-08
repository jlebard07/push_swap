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

WINDOWS = no
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = find_in_stack.c check_error_int_array.c check_error_str.c \
main.c node_init.c push_swap.c reverse_rotate.c rotate.c sort_3.c \
stack_init.c stack_utils.c str_to_int_array.c swap.c
OBJS = $(SRC:.c=.o)
AR = ar rcs

ifeq ($(WINDOWS), yes)
	CLEAN = del /Q
	FCLEAN = del /Q
else 
	CLEAN = rm -rf
	FCLEAN = rm -f
endif

%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<
	
$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf
	cp printf/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(CLEAN) libft/*.o
	$(CLEAN) *.o

fclean: clean
	$(FCLEAN) $(NAME)
	$(FCLEAN) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
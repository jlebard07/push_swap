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
NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AR = ar -rcs

ifeq ($(WINDOWS), yes)
	CLEAN = del /Q
	FCLEAN = del /Q
else 
	CLEAN = rm -rf
	FCLEAN = rm -f
endif

all: $(NAME)
 
$(NAME): $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE): $(OBJS)
	$(AR) $(ARCHIVE) $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(CLEAN) *.o

fclean: clean
	$(FCLEAN) $(NAME)
	$(FCLEAN) *.a


re: fclean all

.PHONY: all clean fclean re
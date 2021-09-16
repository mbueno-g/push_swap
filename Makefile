# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 15:10:38 by mbueno-g          #+#    #+#              #
#    Updated: 2021/09/16 16:26:41 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT = Libft/libft.a

SRC_M = main.c push_functions.c rotate_functions.c swap_functions.c sort_three_to_five.c utils.c ft_lstnew_struct.c print_stack.c quick_sort.c big_sort.c
SRC_B =

OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

N = 0;
N_VALID = $(shell [ $(N) -gt 0 ] && echo True)

ifeq ($(N_VALID), True)
	ARGS := $(shell seq -$(N) $(N) | sort -R | head -n $(N) | tr '\n' ' ')
endif

all: $(NAME)

$(NAME): $(OBJ_M) Libft
		$(CC) $(FLAGS) $(OBJ_M) $(LIBFT) -o $@

$(OBJ_M): $(SRC_M)
		$(CC) $(FLAGS) -c $^

Libft:
	@make all -C Libft/

test: all
	@if [ $(N) -le 0 ]; then \
			echo "Error"; \
	else \
			./$(NAME) $(ARGS); \
	fi

clean:
	make clean -C Libft/
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all Libft clean fclean re

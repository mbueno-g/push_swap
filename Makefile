
NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT = Libft/libft.a

SRC_M = main.c push_functions.c rotate_functions.c swap_functions.c sort_three_to_five.c utils.c
SRC_B =

OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) Libft
		$(CC) $(FLAGS) $(LIBFT) $(OBJ_M) -o $@

$(OBJ_M): $(SRC_M)
		$(CC) $(FLAGS) -c $^

Libft:
	make all -C Libft/

clean:
	make clean -C Libft/
	$(RM) $(OBJ_M) $(OBJ_B)

fclean:
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all Libft clean fclean re

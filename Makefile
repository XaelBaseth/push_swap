NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE = src/op/*.c\
			src/sort/*.c\
			src/utils/*.c\
			src/main.c 

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) - Iincludes -o $(NAME)

all: $(NAME)

clean: @rm -rf src/*.o
		@rm -rf src/op/*.o
		@rm -rf src/sort/*.o
		@rm -rf src/utils/*.o

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
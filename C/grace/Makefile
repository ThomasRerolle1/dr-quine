NAME = Grace
SRCS = Grace.c
OBJ = $(SRCS:%.c=%.o)
CC = clang
CFLAGS = -Wall -Werror -Wextra
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) successfully compiled$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

diff: $(NAME)
	@echo "Executing $(NAME) and comparing output..."
	./$(NAME)
	diff $(NAME).c $(NAME)_kid.c
	@rm -f $(NAME)_kid.c

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -f $(NAME)_kid.c $(NAME)_kid

re: fclean all

.PHONY: all clean fclean re diff

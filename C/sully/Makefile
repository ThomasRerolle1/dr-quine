NAME = Sully
SRCS = Sully.c
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
	@echo "Executing $(NAME) and testing..."
	./$(NAME)
	@echo "Counting generated files:"
	@ls -1 | grep -E "Sully_[0-9]" | wc -l
	@echo "Checking differences:"
	@if [ -f Sully_0.c ]; then \
		echo "Diff between original and Sully_0.c:"; \
		diff $(NAME).c Sully_0.c || true; \
	fi

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -f Sully_*

re: fclean all

.PHONY: all clean fclean re diff
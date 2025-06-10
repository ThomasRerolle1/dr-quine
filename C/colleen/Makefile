NAME= Colleen

SRCS=	Colleen.c

OBJ= $(SRCS:%.cpp=%.o)

CC= gcc

CFLAGS=	-Wall -Werror -Wextra 

GREEN = \033[0;32m
RESET = \033[0m

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) succesfully compiled$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

diff: $(NAME)
	@echo "Compiling with clang, executing and comparing..."
	clang -Wall -Wextra -Werror -o $(NAME) $(NAME).c
	./$(NAME) > tmp_$(NAME)
	diff tmp_$(NAME) $(NAME).c || true
	rm -f tmp_$(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re diff 

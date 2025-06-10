NAME= sully 

SRCS=	sully.c

OBJ= $(SRCS:%.cpp=%.o)

CC= gcc

CFLAGS=	-Wall -Werror -Wextra 

GREEN = \033[0;32m

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) succesfully compiled$(RESET)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all


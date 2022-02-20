NAME= ft_containers

CC= clang++ -g

FLAGS= -Wall -Wextra -Werror -std=c++98

SRCS=   main.cpp

OBJ = $(SRCS:.c=.o)

DELETEOBJ= rm -rf *.o

DELETENAME= rm -rf $(NAME)

all: $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRCS)  -o ft_containers
clean:
	$(DELETEOBJ) $(DELETENAME)

fclean : clean
	rm -rf $(NAME)

re: clean all
.PHONY: clean
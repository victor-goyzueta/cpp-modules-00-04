NAME		= ex00

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXFLAGS	+= -I inc

SRC			=	main.cpp			\
				src/Animal.cpp		\


OBJ			= $(SRC:.cpp=.o)

all:	$(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
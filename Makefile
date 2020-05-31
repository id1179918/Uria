CC		= g++
RM		= rm -rf
NAME	= uria
OBJ		= $(SRC:.cpp=.o)

SRC		= 	sources/Main.cpp				\
			sources/core/Core.cpp			\
			sources/tools/InterfaceTool.cpp	\
			sources/errors/Errors.cpp		\

CXXFLAGS	+= -I sources/core
CXXFLAGS	+= -I sources/errors
CXXFLAGS	+= -I sources/tools
CXXFLAGS	+= -Wall -Wextra -fPIC
CXXFLAGS	+= -std=c++17
CXXFLAGS	+= -g

LDFLAGS		+= -ldl -lncurses

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

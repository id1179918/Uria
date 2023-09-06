#					#
# 	-				#
# 	  -				#
# 	    -			#
# 	  -				#
# 	-				#
# 	Uria - 2021		#
# 					#
# 	Thomas ROUSTAN	#
#	Makefile		#
# 	-				#
# 	  -				#
# 	    -			#
# 	  -				#
# 	-				#
#					#

CC		= g++
RM		= rm -rf
NAME	= uria
OBJ		= $(SRC:.cpp=.o)

SRC		= 	sources/Main.cpp						\
			sources/core/Core.cpp					\
			sources/core/Keys.cpp					\
			sources/ncurses/Ncurses.cpp				\
			sources/ncurses/menu/Menu.cpp			\
			sources/tools/InterfaceTool.cpp			\
			sources/tools/Tool.cpp					\
			sources/file_manager/FileManager.cpp	\
			sources/file_manager/Crypt.cpp			\
			sources/file_manager/Files.cpp			\
			#sources/errors/Errors.cpp				\

CXXFLAGS	+= -I sources/core
#CXXFLAGS	+= -I sources/errors
CXXFLAGS	+= -I sources/file_manager
CXXFLAGS	+= -I sources/tools
CXXFLAGS	+= -I sources/ncurses
CXXFLAGS	+= -I sources/ncurses/menu
CXXFLAGS	+= -Wall -Werror -Wextra -Wsign-compare -fPIC
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

NAME			=	cpp03ex00

INC				=	includes/
SRC_DIR			=	sources/
OBJ_DIR			=	objects/

CC				=	c++
CFLAGS			=	-Wall -Werror -Wextra -std=c++98

RM				=	@rm -f

CPP02_EX00_DIR	=	$(SRC_DIR)main.cpp \

SRCS			=	$(CPP03_EX00_DIR)

OBJS			=	$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
		@echo "\033[1;32mMake .o and $(NAME).\033[0m"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
		$(RM) -r $(OBJ_DIR)
		@echo "\033[1;31mClean .o files.\033[0m"

fclean:		clean
		$(RM) $(NAME)
		@echo "\033[1;31mClean executable/s.\033[0m"

re:		fclean all

.PHONY:	clean fclean re

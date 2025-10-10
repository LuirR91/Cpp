NAME			=	cpp05ex01

INC				=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/

CC				=	c++
CFLAGS			=	-Wall -Werror -Wextra -std=c++98

RM				=	@rm -f

CPP05_EX01_DIR	=	$(SRC_DIR)main.cpp \
					$(SRC_DIR)Bureaucrat.cpp \
					$(SRC_DIR)Form.cpp \

SRCS			=	$(CPP05_EX01_DIR)

OBJS			=	$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

all:			$(NAME)

$(NAME):		$(OBJS)
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
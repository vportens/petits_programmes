NAME =	2048 


CC		=	cc	
CFLAGS 	=	 -Wall -Wextra -Werror 
LIB 	= 	-lncurses	
SRC_DIR = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_DIR), $, $(dir):)

SRCS =  print_game.c				\
	printMap.c				\
	ft_itao.c


OBJ_DIR	=	./objs

# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

all :
	make $(NAME) --no-print-directory

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  $(LIB) -o $(NAME)
	
	

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<  -I incs

$(OBJ_DIR) :
	mkdir -p $@

clean :
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -rf $(NAME)

relinux : fclean LINUX

re : fclean all

##rebonus : fclean bonus

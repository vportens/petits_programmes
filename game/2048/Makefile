NAME =	2048 


CC		=	cc	
CFLAGS 	=	 -Wall -Wextra -Werror 
LIB 	= 	-lncurses	
SRC_DIR = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_DIR), $, $(dir):)

SRCS =  print_game.c				\
	printMap.c				\
	ft_itao.c	\
	print_num_ascii_art.c \
	merge.c \
	move.c \
	play_round.c \
	play_game.c \
	add_tile.c \
	game_over.c	\
	end_screen.c \
	score_page.c	\
	gnl.c \
	strdup.c	\
	strcat.c	\
	strjoin.c	\
	str_new.c	\
	strcpy.c	\
	atoi.c	\
	main.c

HEADER = incs/game.h


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

##relinux : fclean LINUX

re : fclean all

.PHONY : all clean fclean re

##rebonus : fclean bonus

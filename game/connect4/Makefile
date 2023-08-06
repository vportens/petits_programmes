SRCS_DIR	= ./src
SRCS_LIST	= connect4.c display.c init_destroy.c moves.c checks.c utils.c ia.c score_utils.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))

HEADER_DIR	= ./inc
HEADER_LIST	= connect4.h
HEADER		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))

OBJS_DIR	= ./obj
OBJS_LIST	= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

LIBFT_DIR	= ./Libft
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))
LIBFT_HEAD	= $(addprefix $(LIBFT_DIR)/, libft.h)

#CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -g3

ifeq ($(MAKECMDGOALS), debug)
CFLAGS		+= -D DEBUG=1
endif

CC			= cc
NAME		= connect4

all	: $(NAME)
debug : $(NAME)

$(OBJS_DIR)	:
	mkdir -p $@

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c $(HEADER) $(LIBFT_HEAD) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -I $(HEADER_DIR) -I $(LIBFT_DIR) -o $@

$(NAME)	: $(OBJS_LIST) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_LIST) $(LIBFT) -o $@

$(LIBFT) :
	make bonus -C $(LIBFT_DIR)

clean	:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean	: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re	: fclean all

.PHONY : all clean fclean re

NAME = so_long

NAME_B = so_long_bonus

MAC = so_long_mac

MAC_B = so_long_mac_bonus

LIBFT = libft

MLX = minilibx-linux

FLAGS 	= -Wall -Wextra  #-framework OpenGL -framework AppKit libft.a -glldb
 
SRCS =  	srcs_new/main.c 				\
 			srcs_new/error.c 				\
 			srcs_new/gnl_recursif.c 		\
 			srcs_new/parsing.c 				\
 			srcs_new/check_map.c 			\
 			srcs_new/check_inf_map.c 		\
 			srcs_new/init_size_screen.c 	\
 			srcs_new/draw.c 				\
 			srcs_new/draw_utils.c			\
			srcs_new/keycode.c				\
			srcs_new/print_score.c			\
			srcs_new/init_img.c

SRCS_BONUS =	srcs_bonus/main_bonus.c			\
				srcs_bonus/parsing_bonus.c		\
				srcs_bonus/draw_bonus.c			\
				srcs_bonus/error.c				\
				srcs_bonus/gnl_recursif.c		\
				srcs_bonus/init_size_screen.c	\
				srcs_bonus/draw_utils.c 		\
				srcs_bonus/check_map_bonus.c	\
				srcs_bonus/check_inf_map.c	 	\
				srcs_bonus/keycode.c			\
				srcs_bonus/print_score.c		\
				srcs_bonus/init_img.c
 
CC 		= gcc
OBJ 	= ${SRCS:.c=.o}
OBJS 	= *.o
OBJ_B = ${SRCS_BONUS:.c=.o}
OBJS_B = *.o
 
.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
 
all : 
	@make -C $(LIBFT)
	@make -C $(MLX)
	@make $(NAME)

$(NAME)	: $(OBJ) 
	$(CC) $(FLAGS) -I libft/includes/ -I ./ -I minilibx-linux/ $(OBJ) libft/libft.a minilibx-linux/libmlx_Linux.a -lm -lX11 -lXext -lbsd -o $(NAME)
 
$(MAC) : $(OBJ) 
	$(CC) $(FLAGS) -I libft/includes/ -I ./ -I mlx_opengl/ $(OBJ) libft/libft.a mlx_opengl/libmlx.a -framework OpenGL -framework AppKit -o $(MAC) # -lm -lX11 -lXext -lbsd -o $(NAME)

$(NAME_B) : $(OBJ_B)
	$(CC) $(FLAGS) -I libft/includes/ -I ./ -I minilibx-linux/ $(OBJ_B) libft/libft.a minilibx-linux/libmlx_Linux.a -lm -lX11 -lXext -lbsd -o $(NAME_B)

$(MAC_B) : $(OBJ_B)
	$(CC) $(FLAGS) -I libft/includes/ -I ./ -I mlx_opengl/ $(OBJ_B) libft/libft.a mlx_opengl/libmlx.a -framework OpenGL -framework AppKit -o $(MAC_B) # -lm -lX11 -lXext -lbsd -o $(NAME)

clean : 
		@make clean -C $(LIBFT)
		@make clean -C $(MLX)
		@rm -rf $(OBJ)
		@rm -rf $(OBJ_B)
 
fclean : clean
		@make fclean -C $(LIBFT)
		@rm -rf $(OBJS)
		@rm -rf $(OBJS_B)
		@rm -rf $(NAME)
		@rm -rf $(NAME_B)
 
relinux : fclean LINUX
 
re : fclean all
	
 
 
bonus : 
		@make -C $(LIBFT)
		@make -C $(MLX)
		@make ${NAME_B}
 
rebonus : fclean bonus

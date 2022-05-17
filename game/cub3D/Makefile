NAME = cub3D
NAME_B = cub3D_bonus

LIBFT = srcs/cub_classic/libft
##LIBFT_B = srcs/cub_game/libft

CC		=	clang
MLX	 	=	./minilibx_linux
CFLAGS 	=	-g -Wall -Wextra 
LIB 	= 	-L/usr/include -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_DIR), $, $(dir):)

SRCS =  	main.c					\
			gnl.c					\
			parsing.c				\
			get_texturs_nsew.c		\
			get_rgb.c				\
			get_map.c				\
			get_map_utils.c			\
			check_around.c			\
			start.c					\
			draw.c					\
			raycasting.c			\
			color.c					\
			utils_raycast.c			\
			precision_textur.c		\
			get_val_raycast.c		\
			keycode.c				\
			free_all.c				\
			init_stc.c

##SRCS_BONUS =	b_main.c			\
			b_gnl.c					\
			b_parsing.c				\
			b_get_texturs_nsew.c		\
			b_get_rgb.c				\
			b_get_map.c				\
			b_get_map_utils.c			\
			b_check_around.c			\
			b_get_sprit.c				\
			b_free_all.c				\
			b_start.c					\
			b_draw.c					\
			b_raycasting.c			\
			b_color.c					\
			b_utils_raycast.c			\
			b_precision_textur.c		\
			b_get_val_raycast.c		\
			b_keycode.c				\
			b_seeing_sprit.c			\
			b_init_stc.c


OBJ_DIR	=	./objs

# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJS_B = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:%.c=%.o))

all :
	make -C $(LIBFT) --no-print-directory
	make -C $(MLX) --no-print-directory
	make $(NAME) --no-print-directory

##bonus :
##	make -C $(LIBFT_B)
##	make -C $(MLX)
##	make $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(OBJS) minilibx_linux/libmlx_Linux.a srcs/cub_classic/libft/libft.a -Lminilibx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
	
## $(CC) $(CFLAGS) -o $(NAME)  $(OBJS) srcs/cub_classic/libft/libft.a minilibx_linux/libmlx_Linux.a $(LIB) -I srcs/cub_classic/libft/includes/ -I srcs/cub_classic/include/. -Iminilibx_linux

##$(NAME_B) : $(OBJS_B)
##	$(CC) $(CFLAGS) -o $(NAME_B) -I srcs/cub_game/libft/includes/ -I srcs/cub_game/include/. mlx/mlx.h  mlx/mlx_int.h $(OBJS_B) srcs/cub_game/libft/libft.a mlx/libmlx_Linux.a $(LIB)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<  -I/usr/include -Iminilibx_linux -Isrcs/cub_classic/include

$(OBJ_DIR) :
	mkdir -p $@

clean :
		make clean -C $(LIBFT) --no-print-directory
		make clean -C $(MLX) --no-print-directory
		rm -rf $(OBJ_DIR)

fclean : clean
		make fclean -C $(LIBFT) --no-print-directory
		make clean -C $(MLX) --no-print-directory
		rm -rf $(NAME)
	##	rm -rf $(NAME_B)

relinux : fclean LINUX

re : fclean all

##rebonus : fclean bonus

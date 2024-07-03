NAME=fdf
LIBFT_PATH=lib/libft
LIBFT=$(LIBFT_PATH)/libft.a
MLX_PATH=lib/minilibx_macos
MLX=$(MLX_PATH)/libmlx.a
LIBFT_LIB_FLAGS=-L $(LIBFT_PATH) -lft -I $(LIBFT_PATH)
MLX_LIB_FLAGS=-L $(MLX_PATH) -lmlx -I $(MLX_PATH)
SRC = src/
SRCB = src_bonus/
SRCS = $(SRC)main.c $(SRC)system.c $(SRC)map_loader.c $(SRC)utils.c $(SRC)draw_line.c $(SRC)draw_map.c $(SRC)projection.c
SRCBS = $(SRCB)main_bonus.c $(SRCB)system_bonus.c $(SRCB)map_loader_bonus.c $(SRCB)utils_bonus.c $(SRCB)draw_line_bonus.c \
		$(SRCB)draw_map_bonus.c $(SRCB)projection_bonus.c $(SRCB)inputs_bonus.c $(SRCB)key_inputs_bonus.c \
		$(SRCB)mouse_inputs_bonus.c $(SRCB)rotation_bonus.c

CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT_LIB_FLAGS) $(MLX_LIB_FLAGS) -framework OpenGL -framework AppKit

$(MLX):
	make -s -C $(MLX_PATH)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

bonus: $(SRCBS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(SRCBS) -o $(NAME) $(LIBFT_LIB_FLAGS) $(MLX_LIB_FLAGS) -framework OpenGL -framework AppKit

clean:
	make -s -C $(LIBFT_PATH) clean
	make -s -C $(MLX_PATH) clean

fclean:	clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus

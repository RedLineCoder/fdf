NAME=fdf
LIBFT_PATH=lib/libft
LIBFT=$(LIBFT_PATH)/libft.a
MLX_PATH=lib/minilibx_macos
MLX=$(MLX_PATH)/libmlx.a
LIBFT_LIB_FLAGS=-L $(LIBFT_PATH) -lft -I $(LIBFT_PATH)
MLX_LIB_FLAGS=-L $(MLX_PATH) -lft -I $(MLX_PATH)
SRCS = src/main.c src/system.c src/map_loader.c src/utils.c src/draw_line.c src/draw_map.c src/projection.c

CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT_LIB_FLAGS) $(MLX_LIB_FLAGS) -lmlx -framework OpenGL -framework AppKit

$(MLX):
	make -s -C $(MLX_PATH)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

clean:
	make -s -C $(LIBFT_PATH) clean

fclean:	clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus

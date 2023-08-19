
NAME = so_long
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall

SRCS = main.c put_image_pixel.c draw_square.c color_utils.c \
 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c:.o)
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBS_FLAGS = -Lft_printf -lftprintf -Llibft -lft
all: $(NAME)


$(NAME): $(OBJ)
	@make -C ft_printf
	@make -C libft
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS) $(LIBS_FLAGS)

clean:
	@make clean -C ft_printf
	@make clean -C libft
	@make clean -C mlx
	rm -f $(OBJ)
fclean:clean
	@make fclean -C ft_printf
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
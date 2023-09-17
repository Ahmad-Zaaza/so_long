
NAME = so_long
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -fsanitize=address -g3
SHARED_DIR = ../shared

SRCS = main.c ../validations.c $(SHARED_DIR)queue.c ../tiles.c $(SHARED_DIR)/player_controls.c $(SHARED_DIR)/player.c  $(SHARED_DIR)/dfs.c ../map.c $(SHARED_DIR)/font.c utils.c $(SHARED_DIR)/map_validations.c \
 ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)
MLX_FLAGS = -L ../mlx -lmlx -framework OpenGL -framework AppKit
LIBS_FLAGS = -L ../ft_printf -lftprintf -L ../libft -lft


all: $(NAME)


$(NAME): $(OBJ)
	@make -C ../ft_printf
	@make -C ../libft
	@make -C ../mlx
	$(CC) $(CFLAGS) $^ $(LIBS_FLAGS) $(MLX_FLAGS) -o $@

clean:
	@make clean -C ../ft_printf
	@make clean -C ../libft
	@make clean -C ../mlx
	rm -f $(OBJ)
fclean:clean
	@make fclean -C ../ft_printf
	@make fclean -C ../libft
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
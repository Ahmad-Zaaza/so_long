
NAME = so_long
BONUS = bonus
CC = cc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit
LIBS_FLAGS = -L ft_printf -lftprintf -L libft -lft

SRCS_DIR= ./srcs/
OBJS_DIR= ./objs/

SO_LONG_SRCS_DIR = $(SRCS_DIR)/so_long/
BONUS_SRCS_DIR = $(SRCS_DIR)/bonus/
SHARED_SRCS_DIR = $(SRCS_DIR)/shared/

SO_LONG_SRCS = so_long.c draw.c tiles.c player_controls.c is_valid_char.c
BONUS_SRCS = bonus.c coin.c font.c draw_bonus.c tiles_bonus.c player_controls_bonus.c is_valid_char_bonus.c
SHARED_SRCS = queue.c dfs.c player.c  map_validations.c validations.c map.c utils.c draw_utils.c error.c

SO_LONG_SRCS_PATH = $(SO_LONG_SRCS:%=$(SO_LONG_SRCS_DIR)%)
BONUS_SRCS_PATH = $(BONUS_SRCS:%=$(BONUS_SRCS_DIR)%)
SHARED_SRCS_PATH = $(SHARED_SRCS:%=$(SHARED_SRCS_DIR)%)

SO_LONG_OBJS = $(SO_LONG_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
SHARED_OBJS = $(SHARED_SRCS:%.c=%.o)

SO_LONG_OBJS_PATH = $(addprefix $(OBJS_DIR), $(SO_LONG_OBJS))
BONUS_OBJS_PATH = $(addprefix $(OBJS_DIR), $(BONUS_OBJS))
SHARED_OBJS_PATH = $(addprefix $(OBJS_DIR), $(SHARED_OBJS))

SO_LONG_OBJ = $(SO_LONG_OBJS_PATH) $(SHARED_OBJS_PATH)
BONUS_OBJ = $(BONUS_OBJS_PATH) $(SHARED_OBJS_PATH)


all: $(OBJS_DIR) $(NAME)
	@echo "so_long is ready"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(SO_LONG_OBJ)
	@make -C ft_printf
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(SO_LONG_OBJS_PATH) $(SHARED_OBJS_PATH) $(LIBS_FLAGS) $(MLX_FLAGS) -o $@

$(BONUS): $(OBJS_DIR) $(BONUS_OBJ)
	@make -C ft_printf
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(BONUS_OBJS_PATH) $(SHARED_OBJS_PATH) $(LIBS_FLAGS) $(MLX_FLAGS) -o $@
	@echo "bonus is ready!"



$(SO_LONG_OBJS_PATH): $(SO_LONG_SRCS_PATH)
	@$(MAKE) $(SO_LONG_OBJS)

$(SHARED_OBJS_PATH): $(SHARED_SRCS_PATH)
	@$(MAKE) $(SHARED_OBJS)

$(BONUS_OBJS_PATH): $(BONUS_SRCS_PATH)
	@$(MAKE) $(BONUS_OBJS)

$(SO_LONG_OBJS):
	$(CC) $(CFLAGS) -c $(SO_LONG_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

$(SHARED_OBJS):
	$(CC) $(CFLAGS) -c $(SHARED_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

$(BONUS_OBJS):
	$(CC) $(CFLAGS) -c $(BONUS_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

clean:
	@make clean -C ft_printf
	@make clean -C libft
	@make clean -C mlx
	rm -f $(SO_LONG_OBJ) $(BONUS_OBJ)

fclean:clean
	@make fclean -C ft_printf
	@make fclean -C libft
	@make clean -C mlx
	rm -f $(NAME) $(BONUS)

re: fclean all
.PHONY: all clean fclean re
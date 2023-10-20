
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

MLX_FLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit
LIBS_FLAGS = -L ft_printf -lftprintf -L libft -lft

SRCS_DIR= ./srcs/
OBJS_DIR= ./objs/

SO_LONG_SRCS_DIR = $(SRCS_DIR)/so_long/
BONUS_SRCS_DIR = $(SRCS_DIR)/bonus/
SHARED_SRCS_DIR = $(SRCS_DIR)/shared/

SO_LONG_SRCS = so_long.c validations.c  tiles.c  map.c  utils.c
BONUS_SRCS = so_long_bonus.c
SHARED_SRCS = queue.c player_controls.c player.c dfs.c font.c map_validations.c

SO_LONG_SRCS_PATH = $(SO_LONG_SRCS:%=$(SO_LONG_SRCS_DIR)%)
BONUS_SRCS_PATH = $(BONUS_SRCS:%=$(BONUS_SRCS_DIR)%)
SHARED_SRCS_PATH = $(SHARED_SRCS:%=$(SHARED_SRCS_DIR)%)

SO_LONG_OBJS = $(SO_LONG_SRCS:%.c=%.o)
# BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
SHARED_OBJS = $(SHARED_SRCS:%.c=%.o)

SO_LONG_OBJS_PATH = $(addprefix $(OBJS_DIR), $(SO_LONG_OBJS))
# BONUS_OBJS_PATH = $(addprefix $(OBJS_DIR), $(BONUS_OBJS))
SHARED_OBJS_PATH = $(addprefix $(OBJS_DIR), $(SHARED_OBJS))

SO_LONG_OBJ = $(SO_LONG_OBJS_PATH) $(BONUS_OBJS_PATH)
# BONUS_OBJ = $(BONUS_OBJS_PATH) $(BONUS_OBJS_PATH)


all: $(OBJS_DIR) $(NAME)
	@echo "so_long is ready"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(SO_LONG_OBJ)
	@make -C ft_printf
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(SO_LONG_OBJS_PATH) $(SHARED_OBJS_PATH) $(LIBS_FLAGS) $(MLX_FLAGS) -o $@


$(SO_LONG_OBJS_PATH): $(SO_LONG_SRCS_PATH)
	@$(MAKE) $(SO_LONG_OBJS)

$(SHARED_OBJS_PATH): $(SHARED_SRCS_PATH)
	@$(MAKE) $(SHARED_OBJS)

$(SO_LONG_OBJS):
	$(CC) $(CFLAGS) -c $(SO_LONG_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

$(SHARED_OBJS):
	$(CC) $(CFLAGS) -c $(SHARED_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

clean:
	@make clean -C ft_printf
	@make clean -C libft
	@make clean -C mlx
	rm -f $(SO_LONG_OBJ) 

fclean:clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
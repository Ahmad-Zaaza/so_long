
NAME = so_long
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall

OBJ = main.o put_image_pixel.o
# INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
all: $(NAME)

# %.o:%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)

clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
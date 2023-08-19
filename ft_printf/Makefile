NAME = libftprintf.a 

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
UTILS_PATH=./utils

SRCS = ft_printf.c ft_printf_utils.c $(UTILS_PATH)/ft_puthex.c $(UTILS_PATH)/ft_putstr.c

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME)
.o.c: $(SRCS) 
	$(CC) $(CFLAGS) -L . -lftprintf -c $(SRCS) 
$(NAME) : $(OBJECTS)
	$(AR) -rcs $@ $^

PHONY: clean fclean all re bonus
clean:
	rm -f $(OBJECTS) 
fclean: clean
	rm -f $(NAME)
re: fclean all
NAME = fractol

SRC = fractol.c maths.c mlx_utils.c rendering.c events.c libft.c errors.c fractal_types.c dragging.c 

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
MLX_LIB = libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

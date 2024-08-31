NAME = fractol
NAME_BONUS = fractol_bonus

SRC = fractol.c maths.c mlx_utils.c rendering.c events.c libft.c errors.c \
		mandelbrot.c julia.c 

SRC_BONUS = fractol_bonus.c maths_bonus.c mlx_utils_bonus.c \
			rendering_bonus.c events_bonus.c libft_bonus.c errors_bonus.c \
			mandelbrot_bonus.c julia_bonus.c bonus_features.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
# MLX_LIB = libmlx.a

all: $(NAME)

bonus: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	$(MAKE) all -C mlx
	$(CC) $(MLX_FLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation finished: try: ./$(NAME) mandelbrot"

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "Compilation finished: try: ./$(NAME_BONUS) burning_ship"

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) clean -C mlx
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	$(MAKE) clean -C mlx
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re

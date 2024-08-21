// -framework OpenGL -framework AppKit
#include "mlx/mlx.h"
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 700 

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    void *mlx;
    void *mlx_window;
    t_data img;
    int x;
    int y;

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "The Painting!");
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    x = WIDTH * 0.1;
    while (x < WIDTH * 0.9)
    {
        y = HEIGHT * 0.1;
        int i = 1;
        while (y < HEIGHT * 0.9)
        {
            my_mlx_pixel_put(&img, x, y, 0x000001 + (i++ * 2));
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_string_put(mlx, mlx_window, (WIDTH * 0.75), (HEIGHT * 0.95), 0xffffff, "- Pollock");
    mlx_loop(mlx);
}

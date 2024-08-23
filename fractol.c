#include "fractol.h"

void color_pxl(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0;
    z.y = 0;

    c.x = scale(x, COORD_MIN_X, COORD_MAX_X, 0, WIN_WIDTH);
    c.y = scale(y, COORD_MIN_Y, COORD_MAX_Y, 0, WIN_HEIGHT);

    // f(c) Z = Z^2 + C;
    i = 0;
    while (i < ITERATIONS)
    {
        z = add_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > ESCAPE_VALUE)
        {
            color = scale(i, COLOR_BLACK, COLOR_WHITE, 0, ITERATIONS);
            my_mlx_pixel_put(&fractal->img, x, y, color);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->img, x, y, COLOR_BLACK);
}

void fractal_rendering(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            color_pxl(x, y, fractal);
            y++;
        }
        x++;
    }
}

int main(void)
{
    t_fractal fractal;
    // t_img img;

    fractal.connection = mlx_init();
    fractal.win = mlx_new_window(fractal.connection, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    fractal.img.img = mlx_new_image(fractal.connection, WIN_WIDTH, WIN_HEIGHT);
    fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal.img.bits_per_pixel, &fractal.img.line_length, &fractal.img.endian);


    fractal_rendering(&fractal);

    mlx_put_image_to_window(fractal.connection, fractal.win, fractal.img.img, 0, 0);
    mlx_loop(fractal.connection);
}

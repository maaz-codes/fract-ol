#include "fractol.h"

static void color_pxl(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0;
    z.y = 0;
    c.x = (scale(x, fractal->min_x, fractal->max_x, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (scale(y, fractal->min_y, fractal->max_y, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
    // c.x = (scale(x, -2 - fractal->center_a, 2 - fractal->center_a, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    // c.y = (scale(y, 2 - fractal->center_b, -2 - fractal->center_b, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
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
    mlx_put_image_to_window(fractal->connection, fractal->win, fractal->img.img, 0, 0);
}

#include "fractol.h"

static int color_themes(int i, t_fractal *fractal)
{
    if (fractal->color_theme == 1)
        return ((int)scale(i, COLOR_WHITE, COLOR_BLACK, 0, ITERATIONS));
    else if (fractal->color_theme == 2)
        return ((int)scale(i, COLOR_BLACK, COLOR_DARK_GREEN, 0, ITERATIONS));
    else if (fractal->color_theme == 3)
        return ((int)scale(i, COLOR_PURPLE, COLOR_ELECTRIC_PURPLE, 0, ITERATIONS));
    else if (fractal->color_theme == 4)
        return ((int)scale(i, COLOR_MAGENTA, COLOR_BLUE_VIOLET, 0, ITERATIONS));
    else if (fractal->color_theme < 1)
    {
        fractal->color_theme = 4;
        return ((int)scale(i, COLOR_MAGENTA, COLOR_BLUE_VIOLET, 0, ITERATIONS));
    }
    else
    {
        fractal->color_theme = 1;
        return ((int)scale(i, COLOR_BLACK, COLOR_WHITE, 0, ITERATIONS));
    }
}

static void color_pxl(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = (scale(x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (scale(y, 2, -2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
    // Mandelbrot
    // c.x = z.x;
    // c.y = z.y;
    // Julia
    c.x = fractal->c_x;
    c.y = fractal->c_y;
    i = 0;
    while (i < ITERATIONS)
    {
        z = add_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > ESCAPE_VALUE)
        {
            color = color_themes(i, fractal);
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

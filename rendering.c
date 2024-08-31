#include "fractol.h"
#include <math.h>

static int color_themes(int i, t_fractal *fractal)
{
    if (fractal->color_theme == 1)
        return ((int)scale(i, COLOR_WHITE, COLOR_BLACK, 0, fractal->iterations));
    else if (fractal->color_theme == 2)
        return ((int)scale(i, COLOR_BLACK, COLOR_DARK_GREEN, 0, fractal->iterations));
    else if (fractal->color_theme == 3)
        return ((int)scale(i, COLOR_PURPLE, COLOR_ELECTRIC_PURPLE, 0, fractal->iterations));
    else if (fractal->color_theme == 4)
        return ((int)scale(i, COLOR_MAGENTA, COLOR_BLUE_VIOLET, 0, fractal->iterations));
    else if (fractal->color_theme < 1)
    {
        fractal->color_theme = 4;
        return ((int)scale(i, COLOR_MAGENTA, COLOR_BLUE_VIOLET, 0, fractal->iterations));
    }
    else
    {
        fractal->color_theme = 1;
        return ((int)scale(i, COLOR_BLACK, COLOR_WHITE, 0, fractal->iterations));
    }
}

static void color_pxl(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    fractal_values(x, y, fractal, &z, &c);
    i = 0;
    while (i < fractal->iterations)
    {
        if (!ft_strncmp(fractal->name, "burning_ship", 13))
        {
            z.x = fabs(z.x);
            z.y = fabs(-z.y);
        }
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

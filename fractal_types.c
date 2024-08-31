#include "fractol.h"

int mandelbrot(t_fractal *fractal)
{
    fractal->name = "mandelbrot";
    fractal->julia_x = 0;
    fractal->julia_y = 0;
    return (1);
}

int julia(char *num1, char *num2, t_fractal *fractal)
{
    fractal->name = "julia";
    if (!check_complex(num1) || !check_complex(num2))
        return (0);
    fractal->julia_x = ft_atof(num1);
    fractal->julia_y = ft_atof(num2);
    return (1);
}

int burning_ship(t_fractal *fractal)
{
    fractal->name = "burning_ship";
    fractal->julia_x = 0;
    fractal->julia_y = 0;
    return (1);
}

void fractal_values(int x, int y, t_fractal *fractal, t_complex *z, t_complex *c)
{
    if (!ft_strncmp(fractal->name, "mandelbrot", 10))
    {
        z->x = (scale(x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
        z->y = (scale(y, 2, -2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
        c->x = z->x;
        c->y = z->y;
    }
    else if (!ft_strncmp(fractal->name, "burning_ship", 13))
    {
        z->x = (scale(x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
        z->y = (scale(y, -2, 2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
        c->x = z->x;
        c->y = z->y;
    }
    else if (!ft_strncmp(fractal->name, "julia", 6))
    {
        z->x = (scale(x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
        z->y = (scale(y, -2, 2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
}

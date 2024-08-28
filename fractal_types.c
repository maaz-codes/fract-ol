#include "fractol.h"

int mandelbrot(t_fractal *fractal)
{
    fractal->name = MANDELBROT;
    fractal->c_x = 0;
    fractal->c_y = 0;
    return (1);
}

int julia(char *num1, char *num2, t_fractal *fractal)
{
    fractal->name = JULIA;
    if (!check_complex(num1) || !check_complex(num2))
        return (0);
    fractal->c_x = ft_atof(num1);
    fractal->c_y = ft_atof(num2);
    return (1);
}
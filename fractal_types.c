#include "fractol.h"

int mandelbrot(t_fractal *fractal)
{
    fractal->name = MANDELBROT;
    fractal->julia_x = 0;
    fractal->julia_y = 0;
    return (1);
}

int julia(char *num1, char *num2, t_fractal *fractal)
{
    fractal->name = JULIA;
    printf("Running...\n %s %s\n", num1, num2);
    if (!check_complex(num1) || !check_complex(num2))
        return (0);
    fractal->julia_x = ft_atof(num1);
    fractal->julia_y = ft_atof(num2);
    return (1);
}
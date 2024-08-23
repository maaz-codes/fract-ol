#include "fractol.h"

double scale(double num, double new_min, double new_max, double old_min, double old_max) 
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

t_complex square_complex(t_complex number)
{
    t_complex result;

    result.x = (number.x * number.x) - (number.y * number.y);
    result.y =  2 * (number.x * number.y);
    return (result);
}

t_complex add_complex(t_complex a, t_complex b)
{
    t_complex result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return (result);
}

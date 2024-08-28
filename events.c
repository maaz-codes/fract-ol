#include "fractol.h"

void clean_exit(t_fractal *fractal)
{
    mlx_destroy_window(fractal->connection, fractal->win);
    free(fractal->connection);
    exit(0);
}

int handle_no_event(t_fractal *fractal)
{
    mlx_put_image_to_window(fractal->connection, fractal->win, fractal->img.img, 0, 0);
    return (1);
}

int handle_key_release(int keycode, t_fractal *fractal)
{
    if (keycode == 123) //left
        fractal->shift_x += 0.1 * fractal->zoom; 
    else if (keycode == 124) // right
        fractal->shift_x -= 0.1 * fractal->zoom;
    else if (keycode == 126) // up
        fractal->shift_y -= 0.1 * fractal->zoom;
    else if (keycode == 125) // down
        fractal->shift_y += 0.1 * fractal->zoom;
    else if (keycode == 24) // +
        fractal->color_theme += 1;
    else if (keycode == 27) // -
        fractal->color_theme -= 1;
    else if (keycode == 53) // esc
        clean_exit(fractal);
    fractal_rendering(fractal);
    return (1);
}

int handle_mouse_click(int keycode,int x, int y, t_fractal *fractal)
{
    mlx_mouse_get_pos(fractal->win, &x, &y);
    fractal->c_x = (scale(x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    fractal->c_y = (scale(y, 2, -2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;;
    printf("%f %f\n", fractal->c_x, fractal->c_y);
    if (keycode == 5) //wheel_up
    {
        fractal->zoom *= 1.05; 
    }
    else if (keycode == 4) // wheel_down
    {
        fractal->zoom *= 0.95;
    }
    fractal_rendering(fractal);
    return (1);
}
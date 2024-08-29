#include "fractol.h"

void clean_exit(t_fractal *fractal)
{
    mlx_destroy_window(fractal->connection, fractal->win);
    free(fractal->connection);
    exit(0);
}

int handle_no_event(t_fractal *fractal)
{
    fractal_rendering(fractal);
    mlx_put_image_to_window(fractal->connection, fractal->win, fractal->img.img, 0, 0);
    return (1);
}

int handle_key_release(int keycode, t_fractal *fractal)
{
    if (keycode == KEY_LEFT)
        fractal->shift_x += 0.1 * fractal->zoom;
    else if (keycode == KEY_RIGHT)
        fractal->shift_x -= 0.1 * fractal->zoom;
    else if (keycode == KEY_UP)
        fractal->shift_y -= 0.1 * fractal->zoom;
    else if (keycode == KEY_DOWN)
        fractal->shift_y += 0.1 * fractal->zoom;
    else if (keycode == KEY_PLUS)
        fractal->color_theme += 1;
    else if (keycode == KEY_MINUS) 
        fractal->color_theme -= 1;
    else if (keycode == KEY_SPACE_BAR)
        reset_fractal(fractal);
    else if (keycode == KEY_I)
        fractal->iterations += 10;
    else if (keycode == KEY_O)
        fractal->iterations -= 10;
    else if (keycode == KEY_P)
        fractal->motion_flag = !fractal->motion_flag;
    else if (keycode == KEY_ESC)
        clean_exit(fractal);
    printf("keycode = %d\n", keycode);

    fractal_rendering(fractal);
    return (1);
}

void zoom_bonus(t_fractal *fractal, int mouse_x, int mouse_y, int flag)
{
    double x = 0;
    double y = 0;
    double screen_x = 0;
    double screen_y = 0;

    mlx_mouse_get_pos(fractal->win, &mouse_x, &mouse_y);
    x = (scale(mouse_x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    y = (scale(mouse_y, 2, -2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
    if (flag == 1)
        fractal->zoom /= 1.25;
    else if (flag == -1)
        fractal->zoom *= 1.25;
    screen_x = (scale(mouse_x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    screen_y = (scale(mouse_y, 2, -2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
    fractal->shift_x += (x - screen_x);
    fractal->shift_y += (y - screen_y);
}

int handle_mouse_motion(int mouse_x, int mouse_y, t_fractal *fractal)
{
    double x;
    double y;

    x = (scale(mouse_x, -2, 2, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    y = (scale(mouse_y, 2, -2, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
    if (fractal->motion_flag)
    {
        fractal->julia_x = x;
        fractal->julia_y = y;
    }
    return (1);
}

int handle_mouse_click(int keycode,int mouse_x, int mouse_y, t_fractal *fractal)
{
    if (keycode == 1)
        zoom_bonus(fractal, mouse_x, mouse_y, 1);
    else if (keycode == 2)
        zoom_bonus(fractal, mouse_x, mouse_y, -1);
    else if (keycode == 5)
        fractal->zoom /= 1.25;
    else if (keycode == 4)
        fractal->zoom *= 1.25;
    fractal_rendering(fractal);
    return (1);
}

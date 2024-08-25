#include "fractol.h"

void close_window()
{
    printf("closing...\n");
}

void fractal_init(t_fractal *fractal)
{
    fractal->connection = mlx_init();
    fractal->win = mlx_new_window(fractal->connection, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    fractal->img.img = mlx_new_image(fractal->connection, WIN_WIDTH, WIN_HEIGHT);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
    fractal->zoom = 1;
    fractal->shift_x = 0;
    fractal->shift_y = 0;
    fractal->min_x = -2;
    fractal->min_y = 2;
    fractal->max_x = 2;
    fractal->max_y = -2;
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
    else if (keycode == 53)
        close_window();
    
    fractal_rendering(fractal);
    return (1);
}
int handle_mouse_click(int keycode,int x, int y, t_fractal *fractal)
{
    mlx_mouse_get_pos(fractal->win, &x, &y);
    if (keycode == 5) //wheel_up
    {
        fractal->zoom *= 1.05; 
    }
    else if (keycode == 4) // wheel_down
    {
        fractal->zoom *= 0.95;
    }
    else if (keycode == 53)
        close_window();


    fractal_rendering(fractal);

    return (1);
}

int main(void)
{
    t_fractal fractal;

    fractal_init(&fractal);
    fractal_rendering(&fractal);
    mlx_key_hook(fractal.win, handle_key_release, &fractal);
    mlx_mouse_hook(fractal.win, handle_mouse_click, &fractal);

    mlx_put_image_to_window(fractal.connection, fractal.win, fractal.img.img, 0, 0);
    mlx_loop(fractal.connection);
}

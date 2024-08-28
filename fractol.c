#include "fractol.h"

void fractal_init(t_fractal *fractal)
{
    fractal->connection = mlx_init();
    fractal->win = mlx_new_window(fractal->connection, WIN_WIDTH, WIN_HEIGHT, fractal->name);
    fractal->img.img = mlx_new_image(fractal->connection, WIN_WIDTH, WIN_HEIGHT);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
    fractal->zoom = 1;
    fractal->color_theme = 1;
    fractal->shift_x = 0;
    fractal->shift_y = 0;
}

int main(int ac, char **av)
{
    t_fractal fractal;

    if (ac >= 2)
    {
        if (!check_args(ac, av, &fractal))
            return (fractal_menu());
        fractal_init(&fractal);
        fractal_rendering(&fractal);
        mlx_loop_hook(fractal.connection, handle_no_event, &fractal);
        mlx_key_hook(fractal.win, handle_key_release, &fractal);
        mlx_mouse_hook(fractal.win, handle_mouse_click, &fractal);
        mlx_loop(fractal.connection);
        mlx_destroy_window(fractal.connection, fractal.win);
        free(fractal.connection);
    }
    else
        return (fractal_menu());
}

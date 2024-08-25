#include "fractol.h"

static void color_pxl(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0;
    z.y = 0;
    c.x = (scale(x, -2 + fractal->center_a, 2 + fractal->center_a, 0, WIN_WIDTH) * fractal->zoom) + fractal->shift_x;
    c.y = (scale(y, 2 + fractal->center_b, -2 + fractal->center_b, 0, WIN_HEIGHT) * fractal->zoom) + fractal->shift_y;
    i = 0;
    while (i < ITERATIONS)
    {
        z = add_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > ESCAPE_VALUE)
        {
            color = scale(i, COLOR_BLACK, COLOR_WHITE, 0, ITERATIONS);
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
    if (keycode == 5) //wheel_up
        fractal->zoom *= 1.05; 
    else if (keycode == 4) // wheel_down
        fractal->zoom *= 0.95;
    else if (keycode == 53)
        close_window();

    mlx_mouse_get_pos(fractal->win, &x, &y);
    fractal->center_a -= x;
    fractal->center_b -= y;
    
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
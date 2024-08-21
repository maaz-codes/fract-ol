#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
// #include <X11/keysym.h>

#define WIDTH 750
#define HEIGHT 500
#define MLX_ERROR 1

typedef struct	s_vars {
	void	*connection;
	void	*win;
}				t_vars;

int handle_no_event(void *data)
{
    return (1);
}

int handle_key_press(int keycode, t_vars *mlx)
{
    printf("Key code for this key is = %d\n", keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(mlx->connection, mlx->win);
    }
    return (1);
}

int handle_mouse_click(int keycode, int x, int y, t_vars *vars)
{
    if (keycode == 1)
    {
        mlx_mouse_get_pos(vars->win, &x, &y);
        printf("running...\n");
        mlx_pixel_put(vars->connection, vars->win, x, y, 0xff0000);
    }
    else 
        printf("Left click on the mouse...\n");
    return (1);
}

int main(void)
{
    t_vars mlx;
    int x, y;

    mlx.connection = mlx_init();
    if (!mlx.connection)
        return (MLX_ERROR);
    mlx.win = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "Hooking");
    if (!mlx.win)
    {
        free(mlx.connection);
        return (1);
    }
    // Event Handling
    mlx_loop_hook(mlx.connection, handle_no_event, &mlx);
    mlx_key_hook(mlx.win, handle_key_press, &mlx);
    mlx_mouse_hook(mlx.win, handle_mouse_click, &mlx);

    mlx_loop(mlx.connection);

    mlx_destroy_window(mlx.connection, mlx.win);
    free(mlx.connection);
}
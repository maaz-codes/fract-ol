#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN_HEIGHT 800
#define WIN_WIDTH 800
#define WIN_TITLE "Mandelbrot - set"

#define ITERATIONS 100
#define ESCAPE_VALUE 4

// colors
#define COLOR_BLACK      0x000000  // Black
#define COLOR_WHITE      0xFFFFFF  // White
#define COLOR_RED        0xFF0000  // Red
#define COLOR_GREEN      0x00FF00  // Green
#define COLOR_BLUE       0x0000FF  // Blue
#define COLOR_YELLOW     0xFFFF00  // Yellow
#define COLOR_CYAN       0x00FFFF  // Cyan
#define COLOR_MAGENTA    0xFF00FF  // Magenta
#define COLOR_ORANGE     0xFFA500  // Orange
#define COLOR_PURPLE     0x800080  // Purple
#define COLOR_PINK       0xFFC0CB  // Pink
#define COLOR_BROWN      0xA52A2A  // Brown
#define COLOR_GRAY       0x808080  // Gray
#define COLOR_NAVY       0x000080  // Navy
#define COLOR_TEAL       0x008080  // Teal
#define COLOR_LIME       0x00FF00  // Lime



typedef struct  s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}               t_img;

typedef struct  s_fractal {
	void	*connection;
	void	*win;
    t_img   img;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	min_x;
	double 	min_y;
	double 	max_x;
	double  max_y;
	double	center_a;
	double  center_b;
}			    t_fractal;


typedef struct  s_complex
{
    double x; //real
    double y; //imaginary
}               t_complex;

// maths
double          scale(double num, double new_min, double new_max, double old_min, double old_max);
t_complex       add_complex(t_complex a, t_complex b);
t_complex       square_complex(t_complex number);

// mlx_utils
void            my_mlx_pixel_put(t_img *data, int x, int y, int color);

// rendering
void			fractal_rendering(t_fractal *fractal);

#endif
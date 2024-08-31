/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:02:12 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/31 10:29:31 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	color_themes(int i, t_fractal *fractal)
{
	double	j;

	j = i;
	if (fractal->color_theme == 1)
		return ((COLOR_BLACK - COLOR_WHITE) * (i - 0) / (fractal->iterations
				- 0) + COLOR_WHITE);
	else if (fractal->color_theme == 2)
		return ((COLOR_BLACK - COLOR_DARK_GREEN) * (i - 0)
			/ (fractal->iterations - 0) + COLOR_DARK_GREEN);
	else if (fractal->color_theme == 3)
		return ((COLOR_MAGENTA - COLOR_BLUE_VIOLET) * (i - 0)
			/ (fractal->iterations - 0) + COLOR_BLUE_VIOLET);
	else if (fractal->color_theme < 1)
	{
		fractal->color_theme = 3;
		return ((COLOR_MAGENTA - COLOR_BLUE_VIOLET) * (i - 0)
			/ (fractal->iterations - 0) + COLOR_BLUE_VIOLET);
	}
	else
	{
		fractal->color_theme = 1;
		return ((COLOR_BLACK - COLOR_WHITE) * (i - 0) / (fractal->iterations
				- 0) + COLOR_WHITE);
	}
}

void	color_pxl(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		algo_mandelbrot(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "julia", 6))
		algo_julia(x, y, fractal);
	else if (!ft_strncmp(fractal->name, "burning_ship", 13))
		algo_burning_ship(x, y, fractal);
}

void	fractal_rendering(t_fractal *fractal)
{
	int	x;
	int	y;

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
	mlx_put_image_to_window(fractal->connection, fractal->win, fractal->img.img,
		0, 0);
}

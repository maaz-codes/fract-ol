/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 09:02:05 by maakhan           #+#    #+#             */
/*   Updated: 2024/08/31 13:36:51 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	scale(double num, double new_min, double new_max)
{
	return ((new_max - new_min) * (num - 0) / (WIN_WIDTH - 0)
		+ new_min);
}

t_complex	square_complex(t_complex number)
{
	t_complex	result;

	result.x = (number.x * number.x) - (number.y * number.y);
	result.y = 2 * (number.x * number.y);
	return (result);
}

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

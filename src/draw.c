/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:18:07 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/26 14:21:52 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	draw_pixels(float *x, float *y, t_fdf *data)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, *x, *y, data->color);
	*x += data->x_step;
	*y += data->y_step;
}

void	bresenham_w(float x, float y, t_fdf *data)
{
	int			max;
	int			z;
	int			z1;
	float		x1;
	float		y1;

	x1 = x + 1;
	y1 = y;
	z = data->z[(int)y][(int)x] * data->z_scale;
	z1 = data->z[(int)y1][(int)x1] * data->z_scale;
	zoom(&x, &y, data->zoom);
	zoom(&x1, &y1, data->zoom);
	color2(z1, z, data);
	isometric(&x, &y, z, data->angle);
	isometric(&x1, &y1, z1, data->angle);
	shift(&x, &y, data->shift_x, data->shift_y);
	shift(&x1, &y1, data->shift_x, data->shift_y);
	data->x_step = x1 - x;
	data->y_step = y1 - y;
	max = max1(mod(data->x_step), mod(data->y_step));
	data->x_step /= max;
	data->y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
		draw_pixels(&x, &y, data);
}

void	bresenham_h(float x, float y, t_fdf *data)
{
	int			max;
	int			z;
	int			z1;
	float		x1;
	float		y1;

	x1 = x;
	y1 = y + 1;
	z = data->z[(int)y][(int)x] * data->z_scale;
	z1 = data->z[(int)y1][(int)x1] * data->z_scale;
	zoom(&x, &y, data->zoom);
	zoom(&x1, &y1, data->zoom);
	color2(z, z1, data);
	isometric(&x, &y, z, data->angle);
	isometric(&x1, &y1, z1, data->angle);
	shift(&x, &y, data->shift_x, data->shift_y);
	shift(&x1, &y1, data->shift_x, data->shift_y);
	data->x_step = x1 - x;
	data->y_step = y1 - y;
	max = max1(mod(data->x_step), mod(data->y_step));
	data->x_step /= max;
	data->y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
		draw_pixels(&x, &y, data);
}

void	draw(t_fdf *data)
{
	float	x;
	float	y;

	menu_windows(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham_w(x, y, data);
			if (y < data->height - 1)
				bresenham_h(x, y, data);
			x++;
		}
		y++;
	}
}

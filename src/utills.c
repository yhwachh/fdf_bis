/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:19:46 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/26 14:19:49 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(int z1, int z, t_fdf *data)
{
	if (z1 || z)
		data->color = 0x0080FF;
	else
		data->color = 0xFF8000;
}

void	color2(int z, int z1, t_fdf *data)
{
	if (z || z1)
		data->color = 0xFF8000;
	else
		data->color = 0x0080FF;
}

void	isometric(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	shift(float *x, float *y, int shift_x, int shift_y)
{
	*x += shift_x;
	*y += shift_y;
}

void	zoom(float *x, float *y, int zoom)
{
	*x *= zoom;
	*y *= zoom;
}

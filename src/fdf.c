/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:18:17 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/26 14:23:44 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	buttons(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 123)
		data->shift_x -= 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 24)
		data->zoom += 1;
	else if (key == 27)
		data->zoom -= 1;
	else if (key == 12)
		data->z_scale += 1;
	else if (key == 13)
		data->z_scale -= 1;
	else
		return (0);
	return (1);
}

float	max1(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	deal_key(int key, t_fdf *data)
{
	if (buttons(key, data))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->z);
		exit(0);
	}
	return (0);
}

int	ft_close(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
	{
		ft_putstr_fd("use: ./fdf map.fdf\n", 1);
		return (0);
	}
	read_map(argv[1], &data);
	init_param(&data);
	draw(&data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

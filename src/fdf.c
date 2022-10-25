
#include "fdf.h"

int		buttons(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 123)
		data->shift_x -= 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 86 || key == 21)
		data->angle += 0.05;
	else if (key == 88 || key == 22)
		data->angle -= 0.05;
	else if (key == 91 || key == 28)
		data->zoom += 1;
	else if (key == 84 || key == 19)
		data->zoom -= 1;
	else if (key == 92 || key == 25)
		data->z_scale += 1;
	else if (key == 85 || key == 20)
		data->z_scale -= 1;
	else
		return (0);
	return (1);
}

int		deal_key(int key, t_fdf *data)
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

int		main(int argc, char **argv)
{
	t_fdf data;

	if (argc != 2)
	{
		ft_putstr_fd("use: ./fdf map.fdf\n", 1);
		return (0);
	}
	read_map(argv[1], &data);
	default_param(&data);
	draw(&data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

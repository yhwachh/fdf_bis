
#include "fdf.h"

void	default_param(t_fdf *data)
{
	data->angle = 0.6;
	data->zoom = 50;
	data->z_scale = 1;
	data->shift_x = 2000 / 3;
	data->shift_y = 1000 / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 1000, "MAP");
}

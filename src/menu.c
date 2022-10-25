
#include "fdf.h"

void	menu_windows(t_fdf *data)
{
	char *menu;

	menu = "up, down, left, right: move map";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x03fc35, menu);
	menu = "8, 2 -zoom; 4, 6  -rotation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, 0x03fc35, menu);
	menu = "9, 3 - scale z coordiante";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, 0x03fc35, menu);
}

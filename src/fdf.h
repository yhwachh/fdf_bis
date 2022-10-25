
#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

typedef struct
{
	int			width;
	int			height;
	int			**z;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			z_scale;
	double		angle;
	float		x_step;
	float		y_step;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void			read_map(char *name, t_fdf *data);
void			draw(t_fdf *data);
void			menu_windows(t_fdf *data);
void			default_param(t_fdf *data);
float			mod(float i);
float			max1(float a, float b);
void			isometric(float *x, float *y, int z, double angle);
void			shift(float *x, float *y, int shift_x, int shift_y);
void			zoom(float *x, float *y, int zoom);
void			fill_matrix(int *z, char *line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:18:30 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/26 14:26:47 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

typedef struct s_fdf
{
	int		**z;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		z_scale;
	double	angle;
	float	x_step;
	float	y_step;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

void	color(int z1, int z, t_fdf *data);
void	color2(int z, int z1, t_fdf *data);
void	read_map(char *name, t_fdf *data);
void	draw(t_fdf *data);
void	menu_windows(t_fdf *data);
void	init_param(t_fdf *data);
float	mod(float i);
float	max1(float a, float b);
int		ft_close(t_fdf *data);
void	isometric(float *x, float *y, int z, double angle);
void	shift(float *x, float *y, int shift_x, int shift_y);
void	zoom(float *x, float *y, int zoom);

#endif


#include "fdf.h"

float	mod(float i)
{
	return ((i < 0) ? -i : i);
}

float	max1(float a, float b)
{
	return (a > b ? a : b);
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

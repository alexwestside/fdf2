
#include "fdf2.h"

void ft_put_image(t_fdf **fdf, int h, int w, char *s)
{
	(*(*fdf)->mlx).mlx = mlx_init();
	(*(*fdf)->mlx).win = mlx_new_window((*(*fdf)->mlx).mlx, h, w, s);
}
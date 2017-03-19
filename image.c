
#include "fdf2.h"

int ft_key_hook(int key)
{
	if (key == 53)
		exit(0);
	return (1);
}

void ft_put_image(t_fdf **fdf, int h, int w, char *s)
{
	(*(*fdf)->mlx).mlx = mlx_init();
	(*(*fdf)->mlx).win = mlx_new_window((*(*fdf)->mlx).mlx, h, w, s);
	(*(*fdf)->mlx).img = mlx_new_image((*(*fdf)->mlx).mlx, h, w);

	//mlx_loop_hook((*(*fdf)->mlx).mlx, &ft_event, fdf);
	mlx_key_hook((*(*fdf)->mlx).win, ft_key_hook, fdf);

}
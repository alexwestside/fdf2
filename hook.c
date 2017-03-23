
#include "fdf2.h"

int	key_exit(void *p)
{
	(void)p;
	exit (0);
}

int ft_key_hook(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window((*fdf->mlx).mlx, (*fdf->mlx).win);
		exit(0);
	}
	return (1);
}



#include "fdf2.h"


void ft_uprising_coord2(t_map **map, int n, int m)
{
	int i;
	int j;
	int p;

	i = -1;
	p = (*map)->len > (*(*map)->line)->len ? (W_HIGHT - 100) / (*map)->len : (W_HIGHT - 100) / (*(*map)->line)->len;
	while (++i < (*map)->len)
	{
		j = -1;
		while (++j < (*map)->line[i]->len)
		{
			(*map)->line[i]->point[j]->x = (*map)->line[i]->point[j]->x + n;
			(*map)->line[i]->point[j]->y = (*map)->line[i]->point[j]->y + m;
			(*map)->line[i]->point[j]->x1 = (((*map)->line[i]->point[j]->x) * p) + W_WIDTH / 2;
			(*map)->line[i]->point[j]->y1 = (((*map)->line[i]->point[j]->y) * p) + W_HIGHT / 2;
		}
	}
}


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
	if (key == 124)
	{
		ft_uprising_coord2(&fdf->map_z, 1, 0);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);

	}
	return (1);
}


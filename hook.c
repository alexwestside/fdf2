
#include "fdf2.h"


void ft_uprising_coord2(t_map **map_z, t_map **map_c, int n, int m)
{
	int i;
	int j;
	int p;

	i = -1;
	p = (*map_z)->len > (*(*map_z)->line)->len ? (W_HIGHT - 100) / (*map_z)->len : (W_HIGHT - 100) / (*(*map_z)->line)->len;
	while (++i < (*map_z)->len)
	{
		j = -1;
		while (++j < (*map_z)->line[i]->len)
		{
			(*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x + n;
			(*map_z)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y + m;
			(*map_c)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * p + W_WIDTH / 2;
			(*map_c)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y * p + W_HIGHT / 2;
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
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, 1, 0);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 123)
	{
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, -1, 0);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 126)
	{
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, 0, -1);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 125)
	{
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, 0, 1);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	return (1);
}


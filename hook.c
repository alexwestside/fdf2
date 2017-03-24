
#include "fdf2.h"


//void ft_uprising_coord2(t_map **map_z, t_map **map_c, int n, int m)
void ft_uprising_coord2(t_map **map_z, t_map **map_c, float *move)
{
	int i;
	int j;
	float p;

	i = -1;
//	if (move[2])
//		p = (*map_z)->len > (*(*map_z)->line)->len ? (W_HIGHT - 100) / (*map_z)->len : (W_HIGHT - 100) / (*(*map_z)->line)->len;
//	else
		p = (*map_z)->len > (*(*map_z)->line)->len ? (W_HIGHT - 100) / (*map_z)->len : (W_HIGHT - 100) / (*(*map_z)->line)->len;
	while (++i < (*map_z)->len)
	{
		//p = p + move[2];
		j = -1;
		while (++j < (*map_z)->line[i]->len)
		{
			(*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x + move[0];
			(*map_z)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y + move[1];

			move[2] ? (*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * move[2] : 0;
			move[2] ? (*map_z)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y * move[2] : 0;

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

int ft_key_hook(int key, t_fdf *fdf, t_mlx *mlx)
{
	if (key == 53)
	{
		//mlx_destroy_window((*fdf->mlx).mlx, (*fdf->mlx).win);
		exit(0);
	}
	if (key == 124)
	{
		(*mlx).move[0] = 1.5;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 123)
	{
		(*mlx).move[0] = -1;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 126)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = -1;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 125)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = 1;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 78)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 0.91;
		(*mlx).move[3] = 0;
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 69)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 1.09;
		(*mlx).move[3] = 0;
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	return (1);
}


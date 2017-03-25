
#include "fdf2.h"

//void ft_turn_aplicate_z_2(t_map **map_c, t_map **map_z)
//{
//	float gamma;
//
//	gamma = (float)((M_PI * GAMMA) / 180);
//	int i;
//	int j;
//
//	i = -1;
//	while (++i < (*map_c)->len)
//	{
//		j = -1;
//		while (++j < (*map_c)->line[i]->len)
//		{
//			(*map_c)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * cosf(gamma) + (*map_z)->line[i]->point[j]->y * sinf(gamma);
//			(*map_c)->line[i]->point[j]->y = -(*map_z)->line[i]->point[j]->x * sinf(gamma) + (*map_z)->line[i]->point[j]->y * cosf(gamma);
//		}
//	}
//}
//
//void ft_turn_abscissa_x_2(t_map **map_c, t_map **map_z)
//{
//	float alpha;
//
//	alpha = (float)((M_PI * ALPHA) / 180);
//	int i;
//	int j;
//
//	i = -1;
//	while (++i < (*map_c)->len)
//	{
//		j = -1;
//		while (++j < (*map_c)->line[i]->len)
//		{
//			(*map_c)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y * cosf(alpha) - (*map_z)->line[i]->point[j]->z * sinf(alpha);
//			(*map_c)->line[i]->point[j]->z = -(*map_z)->line[i]->point[j]->y * sinf(alpha) + (*map_z)->line[i]->point[j]->z * cosf(alpha);
//		}
//	}
//}
//
//void ft_turn_ordinata_y_2(t_map **map_c, t_map **map_z)
//{
//	float beta;
//
//	beta = (float)((M_PI * BETA) / 180);
//	int i;
//	int j;
//
//	i = -1;
//	while (++i < (*map_c)->len)
//	{
//		j = -1;
//		while (++j < (*map_c)->line[i]->len)
//		{
//			(*map_c)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * cosf(beta) + (*map_z)->line[i]->point[j]->z * sinf(beta);
//			(*map_c)->line[i]->point[j]->z = -(*map_z)->line[i]->point[j]->x * sinf(beta) + (*map_z)->line[i]->point[j]->z * cosf(beta);
//		}
//	}
//}
//
//void ft_matrix_trans_2(t_map **map_c, t_map **map_z)
//{
//	ft_turn_aplicate_z_2(map_c, map_z);
//	ft_turn_abscissa_x_2(map_c, map_z);
//	ft_turn_ordinata_y_2(map_c, map_z);
//}

void ft_uprising_coord2(t_map **map_z, t_map **map_c, float *move)
{
	int i;
	int j;
	float p;

	i = -1;
	p = (*map_z)->len > (*(*map_z)->line)->len ? (W_HIGHT - 100) / (*map_z)->len : (W_HIGHT - 100) / (*(*map_z)->line)->len;
	while (++i < (*map_z)->len)
	{
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

//void ft_coord_update_2(t_map **map_i, t_map **map_z, t_point *center)
//{
//	int p;
//	int i;
//	int j;
//
//	i = -1;
//	while (++i < (*map_i)->len)
//	{
//		j = -1;
//		while (++j < (*map_i)->line[i]->len)
//		{
//			(*map_z)->line[i]->point[j]->x = (*map_i)->line[i]->point[j]->x - center->x;
//			(*map_z)->line[i]->point[j]->y = (*map_i)->line[i]->point[j]->y - center->y+;
//		}
//	}
//}

int ft_key_hook(int key, t_fdf *fdf, t_mlx *mlx)
{
	//ft_coord_update_2(&fdf->map_i, &fdf->map_z, (*fdf->mlx).center);
	if (key == 53)
	{
		mlx_destroy_window((*fdf->mlx).mlx, (*fdf->mlx).win);
		exit(0);
	}
	if (key == 124)
	{
		(*mlx).move[0] = 1.5;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
//		ft_matrix_trans_2(&fdf->map_c, &fdf->map_z);
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 123)
	{
		(*mlx).move[0] = -1;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
//		ft_matrix_trans_2(&fdf->map_c, &fdf->map_z);
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 126)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = -1;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
//		ft_matrix_trans_2(&fdf->map_c, &fdf->map_z);
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 125)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = 1;
		(*mlx).move[2] = 0;
		(*mlx).move[3] = 0;
//		ft_matrix_trans_2(&fdf->map_c, &fdf->map_z);
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 78)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 0.91;
		(*mlx).move[3] = 0;
//		ft_matrix_trans_2(&fdf->map_c, &fdf->map_z);
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	if (key == 69)
	{
		(*mlx).move[0] = 0;
		(*mlx).move[1] = 0;
		(*mlx).move[2] = 1.09;
		(*mlx).move[3] = 0;
//		ft_matrix_trans_2(&fdf->map_c, &fdf->map_z);
		ft_uprising_coord2(&fdf->map_z, &fdf->map_c, mlx->move);
		ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	}
	return (1);
}



#include "fdf2.h"

void	ft_uprising_coord_2(t_map **map_z, float *move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map_z)->len)
	{
		j = -1;
		while (++j < (*map_z)->line[i]->len)
		{
			(*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x + move[0];
			(*map_z)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y + move[1];
			move[2] ? (*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * move[2] : 0;
			move[2] ? (*map_z)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y * move[2] : 0;
			move[2] ? (*map_z)->line[i]->point[j]->z = (*map_z)->line[i]->point[j]->z * move[2] : 0;
		}
	}
}

void	ft_matrix_trans_2(t_angle **angle, t_map **map_z, t_map **map_c, float *move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x;
			(*map_c)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y;
			(*map_c)->line[i]->point[j]->z = (*map_z)->line[i]->point[j]->z;
			if (move[4])
			{
				if (move[5] == 6)
					(*map_z)->line[i]->point[j]->z = (*map_z)->line[i]->point[j]->z * move[4];
				if (move[5] == 7)
					(*map_z)->line[i]->point[j]->z = (*map_z)->line[i]->point[j]->z / move[4];
				(*map_c)->line[i]->point[j]->z = (*map_z)->line[i]->point[j]->z;
			}
		}
	}
	ft_matrix_trans(angle, map_c, move);
}

void	ft_uprising_coord_3(t_map **map_c)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = (*map_c)->len > (*(*map_c)->line)->len ? (W_HIGHT - 300) / (*map_c)->len : (W_HIGHT - 300) / (*(*map_c)->line)->len;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j]->x = (*map_c)->line[i]->point[j]->x * p + W_WIDTH / 2;
			(*map_c)->line[i]->point[j]->y = (*map_c)->line[i]->point[j]->y * p + W_HIGHT / 2;
			(*map_c)->line[i]->point[j]->z = (*map_c)->line[i]->point[j]->z * p + W_HIGHT / 2;
		}
	}
}

int		ft_key_hook(int key, t_fdf *fdf, t_mlx *mlx)
{
	if (key == 53 || key == 124 || key == 123 || key == 126 || key == 125 ||
		key == 78 || key == 69 || key == 89 || key == 91 || key == 92 ||
		key == 86 || key == 87 || key == 88 || key == 116 || key == 121)
		ft_bzero((*mlx).move, sizeof(float) * sizeof((*mlx).move));
	if (key == 53)
	{
		mlx_destroy_window((*fdf->mlx).mlx, (*fdf->mlx).win);
		exit(0);
	}
	if (key == 124 || key == 123 || key == 126 || key == 125 || key == 78 ||
		key == 69 || key == 89 || key == 91 || key == 92 || key == 86 ||
		key == 87 || key == 88 || key == 116 || key == 121)
		ft_key_hook_1(key, &fdf, &mlx);
	return (0);
}

void	ft_key_hook_1(int key, t_fdf **fdf, t_mlx **mlx)
{
	(*mlx)->move[3] = 5.0;
	(*mlx)->move[4] = 1.1;
	(*mlx)->move[5] = 0;
	(key == 124) ? (*mlx)->move[0] = 1.5 : 0;
	(key == 123) ? (*mlx)->move[0] = -1 : 0;
	(key == 126) ? (*mlx)->move[1] = -1 : 0;
	(key == 125) ? (*mlx)->move[1] = 1 : 0;
	(key == 78) ? (*mlx)->move[2] = 0.91 : 0; /*0.91*/
	(key == 69) ? (*mlx)->move[2] = 1.09 : 0; /*1.09*/
	(key == 89) ? (*mlx)->move[5] = 3 : 0;
	(key == 91) ? (*mlx)->move[5] = 4 : 0;
	(key == 92) ? (*mlx)->move[5] = 5 : 0;
	(key == 86) ? (*mlx)->move[5] = 8 : 0;
	(key == 87) ? (*mlx)->move[5] = 9 : 0;
	(key == 88) ? (*mlx)->move[5] = 10 : 0;
	(key == 116) ? (*mlx)->move[5] = 6 : 0;
	(key == 121) ? (*mlx)->move[5] = 7 : 0;
	ft_uprising_coord_2(&(*fdf)->map_z, (*mlx)->move);
	ft_matrix_trans_2(&(*fdf)->mlx->angle, &(*fdf)->map_z, &(*fdf)->map_c, (*mlx)->move);
	ft_uprising_coord_3(&(*fdf)->map_c);
	ft_put_image(fdf, W_HIGHT, W_WIDTH);
}

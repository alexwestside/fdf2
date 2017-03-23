
#include "fdf2.h"

void ft_coord_update(t_point **point_x, t_map **map_x, t_map **map)
{
	int i;
	int j;

	i = -1;
	*map_x = (t_map *)malloc(sizeof(t_map));
	(*map_x)->len = (*map)->len;
	(*map_x)->line = (t_line **)malloc(sizeof(t_line *) * (*map_x)->len + 1);
	(*map_x)->line[(*map_x)->len] = NULL;
	while (++i < (*map_x)->len)
	{
		j = -1;
		(*map_x)->line[i] = (t_line *)malloc(sizeof(t_line));
		(*map_x)->line[i]->point = (t_point **)malloc(sizeof(t_point *) * (*(*map)->line)->len);
		(*map_x)->line[i]->len = (*map)->line[i]->len;
		while (++j < (*map_x)->line[i]->len)
		{
			(*map_x)->line[i]->point[j] = (t_point *)malloc(sizeof(t_point));
			(*map_x)->line[i]->point[j]->x = (*map)->line[i]->point[j]->x + (*point_x)->x;
			(*map_x)->line[i]->point[j]->y = (*map)->line[i]->point[j]->y + (*point_x)->y;;
			(*map_x)->line[i]->point[j]->z = (*map)->line[i]->point[j]->z;
			(*map_x)->line[i]->point[j]->r = (*map)->line[i]->point[j]->r;
			(*map_x)->line[i]->point[j]->g = (*map)->line[i]->point[j]->g;
			(*map_x)->line[i]->point[j]->b = (*map)->line[i]->point[j]->b;
		}
		(*map_x)->line[i]->point[j] = NULL;
	}
}

void ft_map_center(t_mlx **mlx, t_map **map_z, t_map **map_c)
{
	int x_len;
	int y_len;

//	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
//		ft_fdf_error(2);
	(*mlx)->center = (t_point *)malloc(sizeof(t_point));
	(*mlx)->center->x = W_WIDTH / 2;
	(*mlx)->center->y = W_HIGHT / 2;
	(*mlx)->center->z = 0;
	(*mlx)->center->r = 0;
	(*mlx)->center->g = 0;
	(*mlx)->center->b = 0;
	ft_coord_update(&(*mlx)->center, map_c, map_z);
}


void ft_uprising_coord(t_map **map, t_mlx **mlx)
{
	int p;
	int i;
	int j;

	i = -1;
	p = (*map)->len > (*(*map)->line)->len ? (W_HIGHT - 100) / (*map)->len : (W_HIGHT - 100) / (*(*map)->line)->len;
	while (++i < (*map)->len)
	{
		j = -1;
		while (++j < (*map)->line[i]->len)
		{
			(*map)->line[i]->point[j]->x = (*map)->line[i]->point[j]->x * p;
			(*map)->line[i]->point[j]->y = (*map)->line[i]->point[j]->y * p;
		}
	}
}

void ft_map_zero(t_mlx **mlx, t_map **map_i, t_map **map_z, t_map **map_c)
{
	int x_len;
	int y_len;

	x_len = (*(*map_i)->line)->len;
	y_len = (*map_i)->len;
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_fdf_error(2);
	(*mlx)->zero = (t_point *)malloc(sizeof(t_point));
	(*mlx)->zero->x = -(((*map_i)->line[y_len - 1]->point[x_len - 1]->x - (*map_i)->line[0]->point[0]->x) / 2);
	(*mlx)->zero->y = -(((*map_i)->line[y_len - 1]->point[x_len - 1]->y - (*map_i)->line[0]->point[0]->y) / 2);
	(*mlx)->zero->z = 0;
	(*mlx)->zero->r = 0;
	(*mlx)->zero->g = 0;
	(*mlx)->zero->b = 0;
	ft_coord_update(&(*mlx)->zero, map_z, map_i);
	ft_uprising_coord(map_z, mlx);
	ft_map_center(mlx, map_z, map_c);
}
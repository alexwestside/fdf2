
#include "fdf2.h"

void ft_coord_update(t_point **center, t_map **map_X, t_map *map)
{
	int i = -1;
	int j;

	*map_X = (t_map *)malloc(sizeof(t_map));
	(*map_X)->len = (*map).len;
	(*map_X)->line = (t_line **)malloc(sizeof(t_line *) * (*map_X)->len + 1);
	(*map_X)->line[(*map_X)->len] = NULL;
	while (++i < (*map_X)->len)
	{
		j = -1;
		(*map_X)->line[i] = (t_line *)malloc(sizeof(t_line));
		(*map_X)->line[i]->point = (t_point **)malloc(sizeof(t_point *) * (*(map)->line)->len);
		(*map_X)->line[i]->len = (*map).line[i]->len;
		while (++j < (*map_X)->line[i]->len)
		{
			(*map_X)->line[i]->point[j] = (t_point *)malloc(sizeof(t_point));
			(*map_X)->line[i]->point[j]->x = (*map).line[i]->point[j]->x + (*center)->x;
			(*map_X)->line[i]->point[j]->y = (*map).line[i]->point[j]->y + (*center)->y;;
			(*map_X)->line[i]->point[j]->z = (*map).line[i]->point[j]->z;
			(*map_X)->line[i]->point[j]->r = (*map).line[i]->point[j]->r;
			(*map_X)->line[i]->point[j]->g = (*map).line[i]->point[j]->g;
			(*map_X)->line[i]->point[j]->b = (*map).line[i]->point[j]->b;
		}
		(*map_X)->line[i]->point[j] = NULL;
	}
}

void ft_map_center(t_mlx **mlx, t_map *map, t_map **map_c)
{
	int x_len;
	int y_len;

	x_len = (*map->line)->len;
	y_len = map->len;
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_fdf_error(2);
	(*mlx)->center = (t_point *)malloc(sizeof(t_point));
	(*mlx)->center->x = W_WIDTH / 2;
	(*mlx)->center->y = W_HIGHT / 2;
	(*mlx)->center->z = 0;
	(*mlx)->center->r = 0;
	(*mlx)->center->g = 0;
	(*mlx)->center->b = 0;
	ft_coord_update(&(*mlx)->center, map_c, map);
}

void ft_map_zero(t_mlx **mlx, t_map *map, t_map **map_z)
{
	int x_len;
	int y_len;

	x_len = (*map->line)->len;
	y_len = map->len;
//	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
//		ft_fdf_error(2);
	(*mlx)->zero = (t_point *)malloc(sizeof(t_point));
	(*mlx)->zero->x = (map->line[y_len - 1]->point[x_len - 1]->x + map->line[0]->point[0]->x) / 2;
	(*mlx)->zero->y = (map->line[y_len - 1]->point[x_len - 1]->y + map->line[0]->point[0]->y) / 2;
	(*mlx)->zero->z = 0;
	(*mlx)->zero->r = 0;
	(*mlx)->zero->g = 0;
	(*mlx)->zero->b = 0;
	ft_coord_update(&(*mlx)->zero, map_z, map);
}
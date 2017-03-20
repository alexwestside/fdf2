
#include "fdf2.h"

void ft_map_center(t_point **center, t_map **map_c, t_map *map)
{
	int i = 0;
	int j;

	 *map_c = (t_map *)malloc(sizeof(t_map));
	(*map_c)->len = (*map).len;
	(*map_c)->line = (t_line **)malloc(sizeof(t_line *) * (*map_c)->len);
	while (i < (*map_c)->len)
	{
		j = 0;
		(*map_c)->line[i] = (t_line *)malloc(sizeof(t_line));
		(*map_c)->line[i]->point = (t_point **)malloc(sizeof(t_point *) * (*(map)->line)->len);
		(*map_c)->line[i]->len = (*map).line[i]->len;
		while (j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j] = (t_point *)malloc(sizeof(t_point));
			(*map_c)->line[i]->point[j]->x = (*map).line[i]->point[j]->x - (*center)->x;
			(*map_c)->line[i]->point[j]->y = (*map).line[i]->point[j]->y - (*center)->y;;
			(*map_c)->line[i]->point[j]->z = (*map).line[i]->point[j]->z;
			(*map_c)->line[i]->point[j]->r = (*map).line[i]->point[j]->r;
			(*map_c)->line[i]->point[j]->g = (*map).line[i]->point[j]->g;
			(*map_c)->line[i]->point[j]->b = (*map).line[i]->point[j]->b;
			j++;
		}
		(*map_c)->line[i]->point[j] = NULL;
		i++;
	}
}

void ft_count_center(t_mlx **mlx, t_map *map, t_map **map_c)
{
	int x_len;
	int y_len;

	x_len = (*map->line)->len;
	y_len = map->len;
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_fdf_error(2);
	(*mlx)->center = (t_point *)malloc(sizeof(t_point));
	//float i = map->line[y_len - 1]->point[x_len - 1]->x;
	//float j = map->line[0]->point[0]->x;
	(*mlx)->center->x = (map->line[y_len - 1]->point[x_len - 1]->x + map->line[0]->point[0]->x) / 2;
	(*mlx)->center->y = (map->line[y_len - 1]->point[x_len - 1]->y + map->line[0]->point[0]->y) / 2;
	(*mlx)->center->z = 0;
	(*mlx)->center->r = 0;
	(*mlx)->center->g = 0;
	(*mlx)->center->b = 0;
	ft_map_center(&(*mlx)->center, map_c, map);
}

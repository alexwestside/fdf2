
#include "fdf2.h"

void ft_count_center(t_mlx **mlx, t_map *map)
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
}

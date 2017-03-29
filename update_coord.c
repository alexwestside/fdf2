
#include "fdf2.h"

void	ft_coord_update_z(t_point **point_x, t_map **map_i, t_map **map_z, int i)
{
	int j;

	*map_z = (t_map *)malloc(sizeof(t_map));
	(*map_z)->len = (*map_i)->len;
	(*map_z)->line = (t_line **)malloc(sizeof(t_line *) * (*map_z)->len + 1);
	(*map_z)->line[(*map_z)->len] = NULL;
	while (++i < (*map_z)->len)
	{
		j = -1;
		(*map_z)->line[i] = (t_line *)malloc(sizeof(t_line));
		(*map_z)->line[i]->point = (t_point **)malloc(sizeof(t_point *) * (*(*map_i)->line)->len + 1);
		(*map_z)->line[i]->len = (*map_i)->line[i]->len;
		while (++j < (*map_z)->line[i]->len)
		{
			(*map_z)->line[i]->point[j] = (t_point *)malloc(sizeof(t_point));
			(*map_z)->line[i]->point[j]->x = (*map_i)->line[i]->point[j]->x - (*point_x)->x;
			(*map_z)->line[i]->point[j]->y = (*map_i)->line[i]->point[j]->y - (*point_x)->y;
			(*map_z)->line[i]->point[j]->z = (*map_i)->line[i]->point[j]->z;
			(*map_z)->line[i]->point[j]->r = (*map_i)->line[i]->point[j]->r;
			(*map_z)->line[i]->point[j]->g = (*map_i)->line[i]->point[j]->g;
			(*map_z)->line[i]->point[j]->b = (*map_i)->line[i]->point[j]->b;
		}
		(*map_z)->line[i]->point[j] = NULL;
	}
}

void	ft_coord_update_c(t_point **point_x, t_map **map_i, t_map **map_c, int i)
{
	int j;

	*map_c = (t_map *)malloc(sizeof(t_map));
	(*map_c)->len = (*map_i)->len;
	(*map_c)->line = (t_line **)malloc(sizeof(t_line *) * (*map_c)->len + 1);
	(*map_c)->line[(*map_c)->len] = NULL;
	while (++i < (*map_c)->len)
	{
		j = -1;
		(*map_c)->line[i] = (t_line *)malloc(sizeof(t_line));
		(*map_c)->line[i]->point = (t_point **)malloc(sizeof(t_point *) * (*(*map_i)->line)->len + 1);
		(*map_c)->line[i]->len = (*map_i)->line[i]->len;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j] = (t_point *)malloc(sizeof(t_point));
			(*map_c)->line[i]->point[j]->x = (*map_i)->line[i]->point[j]->x - (*point_x)->x;
			(*map_c)->line[i]->point[j]->y = (*map_i)->line[i]->point[j]->y - (*point_x)->y;
			(*map_c)->line[i]->point[j]->z = (*map_i)->line[i]->point[j]->z;
			(*map_c)->line[i]->point[j]->r = (*map_i)->line[i]->point[j]->r;
			(*map_c)->line[i]->point[j]->g = (*map_i)->line[i]->point[j]->g;
			(*map_c)->line[i]->point[j]->b = (*map_i)->line[i]->point[j]->b;
		}
		(*map_c)->line[i]->point[j] = NULL;
	}
}

void	ft_uprising_coord(t_map **map_c)
{
	int	p;
	int	i;
	int	j;

	i = -1;
	p = (*map_c)->len > (*(*map_c)->line)->len ? (W_WIDTH - 600) / (*map_c)->len : (W_HIGHT - 600) / (*(*map_c)->line)->len;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j]->x = (*map_c)->line[i]->point[j]->x * p + W_WIDTH / 2;
			(*map_c)->line[i]->point[j]->y = (*map_c)->line[i]->point[j]->y * p + W_HIGHT / 2;
		}
	}
}

void	ft_map_zero(t_mlx **mlx, t_map **map_i, t_map **map_z, t_map **map_c)
{
	int	x_len;
	int	y_len;

	x_len = (*(*map_i)->line)->len;
	y_len = (*map_i)->len;
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_fdf_error(2);
	ft_init_angle(&(*mlx)->angle);
	(*mlx)->zero = (t_point *)malloc(sizeof(t_point));
	(*mlx)->zero->x = ((*map_i)->line[y_len - 1]->point[x_len - 1]->x - (*map_i)->line[0]->point[0]->x) / 2;
	(*mlx)->zero->y = ((*map_i)->line[y_len - 1]->point[x_len - 1]->y - (*map_i)->line[0]->point[0]->y) / 2;
	(*mlx)->zero->z = 0;
	(*mlx)->zero->r = 0;
	(*mlx)->zero->g = 0;
	(*mlx)->zero->b = 0;
	ft_coord_update_z(&(*mlx)->zero, map_i, map_z, -1);
	ft_coord_update_c(&(*mlx)->zero, map_i, map_c, -1);
	(*mlx)->move[5] = 0;
	ft_matrix_trans(&(*mlx)->angle, map_c, (*mlx)->move);
	ft_uprising_coord(map_c);
}

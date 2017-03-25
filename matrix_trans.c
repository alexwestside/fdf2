
#include "fdf2.h"

void ft_turn_aplicate_z(t_map **map_z)
{
	float gamma;

	gamma = (float)((PI * GAMMA) / 180);
	int i;
	int j;

	i = -1;
	while (++i < (*map_z)->len)
	{
		j = -1;
		while (++j < (*map_z)->line[i]->len)
		{
			(*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * cosf(gamma) + (*map_z)->line[i]->point[j]->y * sinf(gamma);
			(*map_z)->line[i]->point[j]->y = -(*map_z)->line[i]->point[j]->x * sinf(gamma) + (*map_z)->line[i]->point[j]->y * cosf(gamma);
//			(*map_z)->line[i]->point[j]->z = -(*map_z)->line[i]->point[j]->y * sinf(gamma) + (*map_z)->line[i]->point[j]->z * cosf(gamma);
		}
	}
}

void ft_turn_abscissa_x(t_map **map_z)
{
	float alpha;

	alpha = (float)((PI * ALPHA) / 180);
	int i;
	int j;

	i = -1;
	while (++i < (*map_z)->len)
	{
		j = -1;
		while (++j < (*map_z)->line[i]->len)
		{
//			(*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * cosf(alpha) + (*map_z)->line[i]->point[j]->y * sinf(alpha);
			(*map_z)->line[i]->point[j]->y = (*map_z)->line[i]->point[j]->y * cosf(alpha) + (*map_z)->line[i]->point[j]->z * sinf(alpha);
			(*map_z)->line[i]->point[j]->z = -(*map_z)->line[i]->point[j]->y * sinf(alpha) + (*map_z)->line[i]->point[j]->z * cosf(alpha);
		}
	}
}

void ft_turn_ordinata_y(t_map **map_z)
{
	float beta;

	beta = (float)((PI * BETA) / 180);
	int i;
	int j;

	i = -1;
	while (++i < (*map_z)->len)
	{
		j = -1;
		while (++j < (*map_z)->line[i]->len)
		{
			(*map_z)->line[i]->point[j]->x = (*map_z)->line[i]->point[j]->x * cosf(beta) + (*map_z)->line[i]->point[j]->z * sinf(beta);
//			(*map_z)->line[i]->point[j]->y = -(*map_z)->line[i]->point[j]->x * sinf(beta) + (*map_z)->line[i]->point[j]->y * cosf(beta);
			(*map_z)->line[i]->point[j]->z = -(*map_z)->line[i]->point[j]->x * sinf(beta) + (*map_z)->line[i]->point[j]->z * cosf(beta);
		}
	}
}

void ft_matrix_trans(t_map **map_z)
{
	ft_turn_aplicate_z(map_z);
	ft_turn_abscissa_x(map_z);
	ft_turn_ordinata_y(map_z);
}

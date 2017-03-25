
#include "fdf2.h"

void ft_turn_aplicate_z(t_map **map_c)
{
	float gamma;

	gamma = (float)((M_PI * GAMMA) / 180);
	int i;
	int j;

	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j]->x = (*map_c)->line[i]->point[j]->x * cosf(gamma) + (*map_c)->line[i]->point[j]->y * sinf(gamma);
			(*map_c)->line[i]->point[j]->y = -(*map_c)->line[i]->point[j]->x * sinf(gamma) + (*map_c)->line[i]->point[j]->y * cosf(gamma);
		}
	}
}

void ft_turn_abscissa_x(t_map **map_c)
{
	float alpha;

	alpha = (float)((M_PI * ALPHA) / 180);
	int i;
	int j;

	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j]->y = (*map_c)->line[i]->point[j]->y * cosf(alpha) - (*map_c)->line[i]->point[j]->z * sinf(alpha);
			(*map_c)->line[i]->point[j]->z = -(*map_c)->line[i]->point[j]->y * sinf(alpha) + (*map_c)->line[i]->point[j]->z * cosf(alpha);
		}
	}
}

void ft_turn_ordinata_y(t_map **map_c)
{
	float beta;

	beta = (float)((M_PI * BETA) / 180);
	int i;
	int j;

	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			(*map_c)->line[i]->point[j]->x = (*map_c)->line[i]->point[j]->x * cosf(beta) + (*map_c)->line[i]->point[j]->z * sinf(beta);
			(*map_c)->line[i]->point[j]->z = -(*map_c)->line[i]->point[j]->x * sinf(beta) + (*map_c)->line[i]->point[j]->z * cosf(beta);
		}
	}
}

void ft_matrix_trans(t_map **map_c)
{
	ft_turn_aplicate_z(map_c);
	ft_turn_abscissa_x(map_c);
	ft_turn_ordinata_y(map_c);
}

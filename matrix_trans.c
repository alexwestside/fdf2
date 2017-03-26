
#include "fdf2.h"

void ft_turn_aplicate_z(t_angle **angle, t_map **map_c, int id, float *move)
{
	float gamma;

	gamma = (float)((M_PI * ((*angle)->gamma + (id == 3 ? move[3] : 0.0))) / 180);
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

void ft_turn_abscissa_x(t_angle **angle, t_map **map_c, int id, float *move)
{
	float alpha;

	alpha = (float)((M_PI * ((*angle)->alpha + (id == 4 ? move[3] : 0))) / 180);
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

void ft_turn_ordinata_y(t_angle **angle, t_map **map_c, int id, float *move)
{
	float beta;

	beta = (float)((M_PI * ((*angle)->beta + (id == 5 ? move[3] : 0))) / 180);
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

void ft_matrix_trans(t_angle **angle, t_map **map_c, int id, float *move)
{
	ft_turn_aplicate_z(angle, map_c, id, move);
	ft_turn_abscissa_x(angle, map_c, id, move);
	ft_turn_ordinata_y(angle, map_c, id, move);
}


#include "fdf2.h"

void	ft_turn_aplicate_z(t_angle **angle, t_map **map_c, float *move)
{
	float	gamma;
	float	point;
	int		i;
	int		j;

	move[5] == 3 ? (*angle)->gamma = (*angle)->gamma + move[3] : 0;
	move[5] == 8 ? (*angle)->gamma = (*angle)->gamma - move[3] : 0;
	gamma = (float)((M_PI * ((*angle)->gamma)) / 180);
	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			point = (*map_c)->line[i]->point[j]->x;
			(*map_c)->line[i]->point[j]->x = (*map_c)->line[i]->point[j]->x * cosf(gamma) + (*map_c)->line[i]->point[j]->y * sinf(gamma);
			(*map_c)->line[i]->point[j]->y = -point * sinf(gamma) + (*map_c)->line[i]->point[j]->y * cosf(gamma);
		}
	}
}

void	ft_turn_abscissa_x(t_angle **angle, t_map **map_c, float *move)
{
	float	alpha;
	float	point;
	int		i;
	int		j;

	move[5] == 4 ? (*angle)->alpha = (*angle)->alpha + move[3] : 0;
	move[5] == 9 ? (*angle)->alpha = (*angle)->alpha - move[3] : 0;
	alpha = (float)((M_PI * ((*angle)->alpha)) / 180);
	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			point = (*map_c)->line[i]->point[j]->y;
			(*map_c)->line[i]->point[j]->y = (*map_c)->line[i]->point[j]->y * cosf(alpha) - (*map_c)->line[i]->point[j]->z * sinf(alpha);
			(*map_c)->line[i]->point[j]->z = -point * sinf(alpha) - (*map_c)->line[i]->point[j]->z * cosf(alpha);
		}
	}
}

void	ft_turn_ordinata_y(t_angle **angle, t_map **map_c, float *move)
{
	float	beta;
	float	point;
	int		i;
	int		j;

	move[5] == 5 ? (*angle)->beta = (*angle)->beta + move[3] : 0;
	move[5] == 10 ? (*angle)->beta = (*angle)->beta - move[3] : 0;
	beta = (float)((M_PI * ((*angle)->beta)) / 180);
	i = -1;
	while (++i < (*map_c)->len)
	{
		j = -1;
		while (++j < (*map_c)->line[i]->len)
		{
			point = (*map_c)->line[i]->point[j]->x;
			(*map_c)->line[i]->point[j]->x = (*map_c)->line[i]->point[j]->x * cosf(beta) - (*map_c)->line[i]->point[j]->z * sinf(beta);
			(*map_c)->line[i]->point[j]->z = -point * sinf(beta) + (*map_c)->line[i]->point[j]->z * cosf(beta);
		}
	}
}

void	ft_matrix_trans(t_angle **angle, t_map **map_c, float *move)
{
	ft_turn_aplicate_z(angle, map_c, move);
	ft_turn_abscissa_x(angle, map_c, move);
	ft_turn_ordinata_y(angle, map_c, move);
}

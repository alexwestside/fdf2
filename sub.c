
#include "fdf2.h"

void ft_init_angle(t_angle **angle)
{
	*angle = (t_angle *)malloc(sizeof(t_angle));
	(*angle)->alpha = 48.5;
	(*angle)->beta = 0.0;
	(*angle)->gamma = 315.0;
}
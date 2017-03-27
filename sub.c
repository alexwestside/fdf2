
#include "fdf2.h"

void ft_init_angle(t_angle **angle)
{
	*angle = (t_angle *)malloc(sizeof(t_angle));
	(*angle)->alpha = 48.5;
	(*angle)->beta = 0.0;
	(*angle)->gamma = 315.0;
}

void ft_check_fdf(t_map *map_i)
{
	int i;
	int len;

	i = 0;
	len = map_i->line[i]->len;
	while (i < map_i->len)
	{
		if (len != map_i->line[i]->len)
			ft_fdf_error(3);
		i++;
	}
}

void ft_get_color(char **str)
{
	char *s;

	s = *str;
	while (*s)
	{
		tolower(*s);
		s++;
	}
	s = *str;
	while(*s)
	{


	}



}
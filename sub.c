
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

int ft_atoi_base(char *s, int base_len, int num)
{
	size_t len;
	char *base;
	int i;


	base = "0123456789abcdef";
	len = ft_strlen(s);
	while (*s)
	{
		i = -1;
		while (base[++i])
		{
			if (*s == base[i])
			{
				num = num * 16 + i;
				break ;
			}
		}
		s++;
	}
	return (num);
}

void ft_get_color(char *color, t_point **p)
{
	int n;

	n = ft_atoi_base(color, 10, 0);
	(*p)->r = n;
	(*p)->g = n >> 8;
	(*p)->b = n >> 16;
}

void ft_extract_color(char **str, t_point **p)
{
	char *s1;
	char *s2;
	char *color;

	s1 = *str;
	while (*s1)
	{
		if (*s1 == ',')
			break ;
		s1++;
	}
	s1++;
	s2 = s1 + 1;
	if (*s1 == '0' && *s2 == 'x')
	{
		while(*s2)
			s2++;
		color = ft_strndup(s1 + 2, s2 - s1);
		ft_get_color(color, p);
	}
	else
		ft_fdf_error(3);
}
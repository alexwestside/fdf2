
#include "fdf2.h"

void	ft_check_fdf(t_map **map_i)
{
	int	i;
	int	len;

	i = 0;
	len = (*map_i)->line[i]->len;
	while (i < (*map_i)->len)
	{
		if (len != (*map_i)->line[i]->len)
			ft_fdf_error(3);
		i++;
	}
}

void	ft_tolower_str(char **str)
{
	char	*s;

	s = *str;
	while (*s)
	{
		*s = (char)ft_tolower(*s);
		s++;
	}
}

int		ft_atoi_base(char *s, int num)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
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

void	ft_get_color(char *color, t_point **p)
{
	int	n;

	ft_tolower_str(&color);
	n = ft_atoi_base(color, 0);
	(*p)->r = n;
	(*p)->g = n >> 8;
	(*p)->b = n >> 16;
}

int		ft_extract_color(char **str, t_point **p, int i)
{
	char	*s1;
	char	*s2;

	s1 = *str;
	while (*s1)
	{
		if (*s1 == ',')
		{
			s2 = s1 + 1;
			if (*(++s1) == '0' && *(++s2) == 'x')
			{
				i = 1;
				while (*s2)
					s2++;
				ft_get_color(ft_strndup(s1 + 2, s2 - s1), p);
			}
			else
				ft_fdf_error(3);
		}
		s1++;
	}
	return (!i ? 0 : 1);
}

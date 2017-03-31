
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

void	ft_help_window(t_fdf *fdf, int i, int y)
{
	char	**str;

	ft_init_help_comand(&str);
	while (str[++i])
	{
		if (i == 1 || i == 3 || i == 6 || i == 10 || i == 13)
			mlx_string_put(fdf->mlx->mlx, fdf->help, 0, y, 0xFF00, str[i]);
		else
			mlx_string_put(fdf->mlx->mlx, fdf->help, 0, y, 0xFFFFFF, str[i]);
		y += 20;
	}
}

void	ft_init_help_comand(char ***str)
{
	*str = (char **)malloc(sizeof(char *) * 18);
	(*str)[0] = "___________________________";
	(*str)[1] = "|       CONTROLS:         |";
	(*str)[2] = "___________________________";
	(*str)[3] = "| >>>>> Translation <<<<< |";
	(*str)[4] = "| Y: Key: UP, DOWN        |";
	(*str)[5] = "| X: Key: LEFT, RIGHT     |";
	(*str)[6] = "| >>>>> Rotation <<<<<    |";
	(*str)[7] = "| X: Keypad: 5, 8         |";
	(*str)[8] = "| Y: Keypad: 4, 7         |";
	(*str)[9] = "| Z: Keypad: 6, 9         |";
	(*str)[10] = "| >>>>> Zoom <<<<<        |";
	(*str)[11] = "| IN: Keypad: +           |";
	(*str)[12] = "| OUT: Keypad: -          |";
	(*str)[13] = "| >>>>> Size Z <<<<<      |";
	(*str)[14] = "| UP: Keypad: 116         |";
	(*str)[15] = "| DOWN: Keypad: 121       |";
	(*str)[16] = "___________________________";
	(*str)[17] = NULL;
}

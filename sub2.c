
#include "fdf2.h"

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

void ft_sub(t_map **map_1, t_map **map_2, int *i, int *j)
{
	(*map_1)->line[*i]->point[*j]->z = (*map_2)->line[*i]->point[*j]->z;
	(*map_1)->line[*i]->point[*j]->r = (*map_2)->line[*i]->point[*j]->r;
	(*map_1)->line[*i]->point[*j]->g = (*map_2)->line[*i]->point[*j]->g;
	(*map_1)->line[*i]->point[*j]->b = (*map_2)->line[*i]->point[*j]->b;
}
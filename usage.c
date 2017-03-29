
#include "fdf2.h"

void	ft_fdf_error(int id)
{
	if (id == 1)
	{
		ft_printf("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit(EXIT_FAILURE);
	}
	else if (id == 2)
	{
		ft_printf("malloc error!!!\n");
		exit(EXIT_FAILURE);
	}
	else if (id == 3)
	{
		ft_printf("file error!!!\n");
		exit(EXIT_FAILURE);
	}
}

int		key_exit(void *p)
{
	(void)p;
	exit(0);
}

void	ft_init_angle(t_angle **angle)
{
	*angle = (t_angle *)malloc(sizeof(t_angle));
	(*angle)->alpha = 48.5;
	(*angle)->beta = 0.0;
	(*angle)->gamma = 315.0;
}


#include "fdf2.h"

void ft_fdf_error(int id)
{
	if (id == 1)
	{
		ft_printf("Usage : ./fdf <filename> [ case_size z_size ]");
		exit(EXIT_FAILURE);
	}
	else if (id == 2)
	{
		ft_printf("malloc error!!!");
		exit(EXIT_FAILURE);
	}
	else if (id == 3)
	{
		ft_printf("file error!!!");
		exit(EXIT_FAILURE);
	}



}
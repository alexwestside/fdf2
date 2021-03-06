
#include "fdf2.h"

int		ft_init_lines(t_line ***line, char *s, int fd)
{
	int		cl;
	char	*tmp;

	cl = 0;
	if ((fd = open(s, O_RDONLY)) < 0)
		ft_fdf_error(3);
	while(get_next_line(fd, &tmp))
		cl++;
	close(fd);
	if (!(*line = (t_line **)malloc(sizeof(t_line *) * (cl + 1))))
		ft_fdf_error(2);
	if (cl == 0)
		return (1);

//	while (read(fd, &tmp, 1))
//	{
//		if (tmp == '\n')
//			cl++;
//	}
//	close(fd);
//	if (!(*line = (t_line **)malloc(sizeof(t_line *) * (cl + 1))))
//		ft_fdf_error(2);
//	if (cl == 0)
//		return (1);
	return (cl);
}

void	ft_init_coord(char *str, t_point **p, int *y, int *x)
{
	int	i;

	if (!(*p = (t_point *)malloc(sizeof(t_point))))
		ft_fdf_error(2);
	(*p)->x = *x;
	(*p)->y = *y;
	(*p)->z = ft_atoi(str);
	i = ft_extract_color(&str, p, 0);
	if (!i)
	{
		(*p)->r = 0xFFFFFF;
		(*p)->g = 0xFFFFFF >> 8;
		(*p)->b = 0xFFFFFF >> 16;
	}
}

void	ft_init_points(char *s, t_line **l, int *y)
{
	char	**str;
	int		cp;
	t_point	**p;
	int		x;

	x = 0;
	cp = 0;
	str = ft_strsplit(s, ' ');
	while (str[cp])
		cp++;
	!(*l = (t_line *)malloc(sizeof(t_line))) ? ft_fdf_error(2) : 0;
	!((*l)->point = (t_point **)malloc(sizeof(t_point *) * cp + 1)) ? ft_fdf_error(2) : 0;
	p = (*l)->point;
	(*l)->len = cp;
	while (*str)
	{
		ft_init_coord(*str, p, y, &x);
		p++;
		str++;
		x++;
	}
	*p = NULL;
}

void	ft_parse_fdf(t_map **map, char *s, int fd)
{
	char	*tmp;
	int		y;
	t_line	**l;

	y = 0;
	(*map) = (t_map *)malloc(sizeof(t_map));
	(*map)->line = NULL;
	(*map)->len = 0;
	(*map)->len = ft_init_lines(&((*map)->line), s, fd);
	l = (*map)->line;
	if ((fd = open(s, O_RDONLY)) < 0)
		ft_fdf_error(3);
	while (get_next_line(fd, &tmp))
	{
		ft_init_points(tmp, l, &y);
		y++;
		l++;
	}
	if (y == 0)
		ft_fdf_error(3);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		ft_fdf_error(1);
	!(fdf = (t_fdf *)malloc(sizeof(t_fdf))) ? ft_fdf_error(2) : 0;
	ft_parse_fdf(&fdf->map_i, av[1], 0);
	ft_check_fdf(fdf->map_i);
	ft_map_zero(&fdf->mlx, &fdf->map_i, &fdf->map_z, &fdf->map_c);
	ft_get_window(&fdf, W_HIGHT, W_WIDTH, "42 fdf");
	ft_put_image(&fdf, W_HIGHT, W_WIDTH);
	fdf->help = mlx_new_window(fdf->mlx->mlx, 280, 350, "HELP");
	ft_help_window(fdf, -1, 0);
	mlx_hook(fdf->mlx->win, 2, 5, ft_key_hook, fdf);
	mlx_hook(fdf->mlx->win, 17, 0, key_exit, fdf);
	mlx_loop(fdf->mlx->mlx);
}

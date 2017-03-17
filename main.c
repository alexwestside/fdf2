
#include "fdf2.h"

void ft_init_lines(t_line ***line, char *s, int fd)
{
	int cl;
	char tmp;

	cl = 0;
	fd = open(s, O_RDONLY);
	while (read(fd, &tmp, 1))
	{
		if (tmp == '\n')
			cl++;
	}
	close(fd);
	*line = (t_line **)malloc(sizeof(t_line *) * (cl + 1));
}

void ft_init_coord(char *str, t_point **p, int *y, int *x)
{
	*p = (t_point *) malloc(sizeof(t_point));
	(*p)->x = *x;
	(*p)->y = *y;
	(*p)->z = ft_atoi(str);
	(*p)->r = 0;
	(*p)->g = 0;
	(*p)->b = 0;
}

void ft_init_points(char *s, t_line **l, int *y)
{
	char **str;
	int cp;
	t_point **p;
	int x;

	x = 0;
	cp = 0;
	str = ft_strsplit(s, ' ');
	while(str[cp])
		cp++;
	*l = (t_line *)malloc(sizeof(t_line));
	(*l)->point = (t_point **)malloc(sizeof(t_point *) * cp);
	p = (*l)->point;
	while (*str)
	{
		ft_init_coord(*str, p, y, &x);
		p++;
		str++;
		x++;
	}
	*p = NULL;
}

void ft_parse_fdf(t_map **map, char *s, int fd)
{
	char *tmp;
	int y;
	t_line **l;

	y = 0;
	(*map) = (t_map *)malloc(sizeof(t_map));
	(*map)->line = NULL;
	(*map)->len = 0;
	//l = (*map)->line;
	ft_init_lines(&((*map)->line), s, fd);
	l = (*map)->line;
	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		ft_init_points(tmp, l, &y);
		y++;
		l++;
	}
}

int main(int ac, char **av)
{
	t_fdf *fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_parse_fdf(&fdf->map, av[1], 0);


	fdf->mlx = (t_mlx *)malloc(sizeof(t_mlx));
}
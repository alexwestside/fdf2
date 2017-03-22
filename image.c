
#include "fdf2.h"

int ft_draw_out(t_point **p)
{
	if (((*p)->x > W_WIDTH || (*p)->x < 0) && ((*p)->y > W_HIGHT || (*p)->y < 0))
		return (0);
	else
		return (1);
}

void ft_draw_line(t_point **p1, t_point **p2, t_map *m)
{
	if(!ft_draw_out(p1) && !ft_draw_out(p2))
		return ;


}

void ft_draw_map_c(t_fdf **fdf)
{
	t_map *m;
	t_point *p1;
	t_point *p2;
	t_point *p3;
	int i;
	int j;

	m = (*fdf)->map_c;
	i = -1;
	while (i++ < m->len)
	{
		j = -1;
		while (j++ < m->line[i]->len)
		{
			p1 = m->line[i]->point[j];
			p2 = m->line[i]->point[j + 1];
			p3 = m->line[i + 1]->point[j];
			if (p2)
				ft_draw_line(&p1, &p2, m);
			if (p3)
				ft_draw_line(&p1, &p3, m);
		}
	}
}

int ft_key_hook(int key)
{
	if (key == 53)
		exit(0);
	return (1);
}

void ft_put_image(t_fdf **fdf, int h, int w, char *s)
{
	(*(*fdf)->mlx).mlx = mlx_init();
	(*(*fdf)->mlx).win = mlx_new_window((*(*fdf)->mlx).mlx, h, w, s);
	(*(*fdf)->mlx).img = mlx_new_image((*(*fdf)->mlx).mlx, h, w);
	(*(*fdf)->mlx).img_str = mlx_get_data_addr((*(*fdf)->mlx).img, &((*(*fdf)->mlx).bpp),&((*(*fdf)->mlx).s_line), &((*(*fdf)->mlx).endian));

	mlx_key_hook((*(*fdf)->mlx).win, ft_key_hook, fdf);

	ft_draw_map_c(fdf);




	mlx_loop((*(*fdf)->mlx).mlx);

//	(*(*fdf)->map_c)

}
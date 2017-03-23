
#include "fdf2.h"

int ft_draw_out(t_point p)
{
	if (p.x > W_WIDTH - 10 || p.x <= 10 || p.y > W_HIGHT - 10 || p.y <= 10)
		return (0);
	else
		return (1);
}

void ft_draw_pixel(t_point p, t_map map, t_mlx **mlx, int color)
{
	int i;

	i = (((int)p.x * 4) + ((int)p.y * (*mlx)->s_line));
	i < 0 ? i = -i : 0;
	(*mlx)->img_str[i] = color;
	(*mlx)->img_str[++i] = color >> 8;
	(*mlx)->img_str[++i] = color >> 16;
}

void ft_draw_line(t_point p1, t_point p2, t_map m, t_mlx **mlx)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int error;

	dx = 0;
	dy = 0;
	sx = 0;
	dy = 0;
	error = 0;
	if(!ft_draw_out(p1) && !ft_draw_out(p2))
		return ;
	dx = (int)fabsf(p1.x - p2.x);
	dy = (int)fabsf(p1.y - p2.y);
	sx = p1.x < p2.x ? 1 : -1;
	sy = p1.y < p2.y ? 1 : -1;
	ft_draw_pixel(p2, m, mlx, 0xFFFFFF);
	while ((p1).x != (p2).x || (p1).y != (p2).y)
	{
		ft_draw_pixel(p1, m, mlx, 0xFFFFFF);
		error = (dx - dy) * 2;
		if (error > -dy)
		{
			error -= dy;
			p1.x += sx;
		}
		if (error < dx)
		{
			error += dx;
			p1.y += sy;
		}
	}
}

void ft_draw_map_c(t_fdf **fdf)
{
	t_map m;
	t_point *p1;
	t_point *p2;
	t_point *p3;
	int i;
	int j;

	m = (*(*fdf)->map_c);
	i = -1;
	while (++i < m.len)
	{
		j = -1;
		while (++j < m.line[i]->len)
		{
			p1 = m.line[i]->point[j];
			p2 = m.line[i]->point[j + 1] ? m.line[i]->point[j + 1] : NULL;
			p3 = m.line[i + 1] ? m.line[i + 1]->point[j] : NULL;
			if (p1 && p2)
				ft_draw_line(*p1, *p2, m, &(*fdf)->mlx);
			if (p1 && p3)
				ft_draw_line(*p1, *p3, m, &(*fdf)->mlx);
		}
	}
}

void ft_get_window(t_fdf **fdf, int h, int w, char *s)
{
	(*(*fdf)->mlx).mlx = mlx_init();
	(*(*fdf)->mlx).win = mlx_new_window((*(*fdf)->mlx).mlx, h, w, s);
}

void ft_put_image(t_fdf **fdf, int h, int w)
{
	(*(*fdf)->mlx).img = mlx_new_image((*(*fdf)->mlx).mlx, h, w);
	(*(*fdf)->mlx).img_str = mlx_get_data_addr((*(*fdf)->mlx).img, &((*(*fdf)->mlx).bpp), &((*(*fdf)->mlx).s_line), &((*(*fdf)->mlx).endian));
	ft_draw_map_c(fdf);
	mlx_put_image_to_window((*(*fdf)->mlx).mlx, (*(*fdf)->mlx).win, (*(*fdf)->mlx).img, 0, 0);
	mlx_destroy_image((*fdf)->mlx->mlx, (*fdf)->mlx->img);

}
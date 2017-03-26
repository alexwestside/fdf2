
#include "fdf2.h"

void ft_draw_pixel(t_point p, t_map map, t_mlx **mlx, int color)
{
	int i;

	i = (((int)p.x * 4) + ((int)p.y * (*mlx)->s_line));
	//i < 0 ? i = -i : 0;
	if (i >= 0 && i < W_WIDTH * 4 * W_HIGHT && p.x > 0 && p.x < W_WIDTH && p.y > 0)
	{
		(*mlx)->img_str[i] = color;
		(*mlx)->img_str[++i] = color >> 8;
		(*mlx)->img_str[++i] = color >> 16;
	}
}

void ft_draw_line(t_point p1, t_point p2, t_map m, t_mlx **mlx)
{
	const int dx = (int)fabsf((int)p1.x - (int)p2.x);
	const int dy = (int)fabsf((int)p1.y - (int)p2.y);
	const int sx = p1.x < (int)p2.x ? 1 : -1;
	const int sy = p1.y < (int)p2.y ? 1 : -1;
	int error = dx - dy;
	ft_draw_pixel(p2, m, mlx, 0xFFFFFF);
	while (((int)p1.x != (int)p2.x|| (int)p1.y != (int)p2.y) && ((int)p1.x > 0 && (int)p1.y < W_HIGHT && (int)p1.x < W_WIDTH && (int)p1.y > 0))
	{
		ft_draw_pixel(p1, m, mlx, 0xFFFFFF);
		const int error2 = error * 2;
		if (error2 > -dy)
		{
			error -= dy;
			p1.x += sx;
		}
		if (error2 < dx)
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
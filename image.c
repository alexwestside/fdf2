
#include "fdf2.h"

int ft_draw_out(t_point p)
{
	//if (p.x > W_WIDTH + 10 || p.x <= 10 || p.y > W_HIGHT - 10 || p.y <= 10)
	if (p.x > W_WIDTH + 10 || p.x < 0/* || p.y > W_HIGHT - 10 || p.y <= 10*/)
		return (0);
	else
		return (1);
}

void ft_draw_pixel(t_point p, t_map map, t_mlx **mlx, int color)
{
	int i;

	i = (((int)p.x * 4) + ((int)p.y * (*mlx)->s_line));
	i < 0 ? i = -i : 0;
	if (i >= 0 && i < W_WIDTH * 4 * W_HIGHT/* && p.x > 0 && p.x < W_WIDTH - 1 && p.y > 0*/)
	{
		(*mlx)->img_str[i] = color;
		(*mlx)->img_str[++i] = color >> 8;
		(*mlx)->img_str[++i] = color >> 16;
	}
}

void ft_draw_line(t_point p1, t_point p2, t_map m, t_mlx **mlx)
{
//	const int dx;
//	const int dy;
//	const int sx;
//	const int sy;
//	const int error;

//	if(!ft_draw_out(p1) && !ft_draw_out(p2))
//		return ;
	const float dx = fabsf((int)p1.x - (int)p2.x);
	const float dy = fabsf((int)p1.y - (int)p2.y);
	const float sx = (int)p1.x < (int)p2.x ? 1 : -1;
	const float sy = (int)p1.y < (int)p2.y ? 1 : -1;
	float error = dx - dy;
	ft_draw_pixel(p2, m, mlx, 0xFFFFFF);
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y) && ((int)p1.x > 0 && (int)p1.y < W_HIGHT && (int)p1.x < W_HIGHT && (int)p1.y > 0))
	{
		ft_draw_pixel(p1, m, mlx, 0xFFFFFF);
		const float error2 = error * 2;
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
		ft_printf("ok\n");
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

#include "fdf2.h"

void	ft_draw_pixel(t_point p, t_mlx **mlx)
{
	int	i;

	i = (((int)p.x * 4) + ((int)p.y * (*mlx)->s_line));
	if (i >= 0 && i <= W_WIDTH * 4 * W_HIGHT && ((int)p.x >= 0 && (int)p.x <= W_WIDTH) && ((int)p.y >= 0 && (int)p.y <= W_HIGHT))
	{
		(*mlx)->img_str[i] = (char)p.r;
		(*mlx)->img_str[++i] = (char)p.g;
		(*mlx)->img_str[++i] = (char)p.b;
	}
}

void	ft_draw_line(t_point p1, t_point p2, t_mlx **mlx)
{
	int			error;
	const int	dx = (int)fabsf((int)p1.x - (int)p2.x);
	const int	dy = (int)fabsf((int)p1.y - (int)p2.y);
	const int	sx = p1.x < (int)p2.x ? 1 : -1;
	const int	sy = p1.y < (int)p2.y ? 1 : -1;

	error = dx - dy;
	ft_draw_pixel(p2, mlx);
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y) && ((int)p1.x > 0 && (int)p1.y < W_HIGHT && (int)p1.x < W_WIDTH && (int)p1.y > 0))
	{
		ft_draw_pixel(p1, mlx);
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

void	ft_draw_map_c(t_fdf **fdf)
{
	t_point	*p1;
	t_point	*p2;
	t_point	*p3;
	int		i;
	int		j;

	i = -1;
	while (++i < (*fdf)->map_c->len)
	{
		j = -1;
		while (++j < (*fdf)->map_c->line[i]->len)
		{
			p1 = (*fdf)->map_c->line[i]->point[j];
			p2 = (*fdf)->map_c->line[i]->point[j + 1] ? (*fdf)->map_c->line[i]->point[j + 1] : NULL;
			p3 = (*fdf)->map_c->line[i + 1] ? (*fdf)->map_c->line[i + 1]->point[j] : NULL;
			if (p1 && p2)
				ft_draw_line(*p1, *p2, &(*fdf)->mlx);
			if (p1 && p3)
				ft_draw_line(*p1, *p3, &(*fdf)->mlx);
		}
	}
}

void	ft_get_window(t_fdf **fdf, int h, int w, char *s)
{
	(*(*fdf)->mlx).mlx = mlx_init();
	(*(*fdf)->mlx).win = mlx_new_window((*(*fdf)->mlx).mlx, h, w, s);
}

void	ft_put_image(t_fdf **fdf, int h, int w)
{
	(*(*fdf)->mlx).img = mlx_new_image((*(*fdf)->mlx).mlx, h, w);
	(*(*fdf)->mlx).img_str = mlx_get_data_addr((*(*fdf)->mlx).img, &((*(*fdf)->mlx).bpp), &((*(*fdf)->mlx).s_line), &((*(*fdf)->mlx).endian));
	ft_draw_map_c(fdf);
	mlx_put_image_to_window((*(*fdf)->mlx).mlx, (*(*fdf)->mlx).win, (*(*fdf)->mlx).img, 0, 0);
	mlx_destroy_image((*fdf)->mlx->mlx, (*fdf)->mlx->img);
}

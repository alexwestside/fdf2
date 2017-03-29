
#ifndef FDF2_FDF2_H
#define FDF2_FDF2_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include <mlx.h>
# include <math.h>
# define W_HIGHT 800
# define W_WIDTH 800

typedef struct 		s_angle
{
	float alpha;
	float beta;
	float gamma;
}					t_angle;

typedef struct		s_point
{
	float 			x;
	float 			y;
	float 			z;
	int				r;
	int				g;
	int				b;
//	int				color;
}					t_point;

typedef struct		s_line
{
	t_point			**point;
	int				len;
}					t_line;

typedef struct		s_map
{
	t_line			**line;
	int				len;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
	int				bpp;
	int				endian;
	int				s_line;
	t_point			*cente;
	t_point			*zero;
	float			move[5];
	t_angle			*angle;
}					t_mlx;

typedef	struct		s_fdf
{
	t_map			*map_i;
	t_map			*map_c;
	t_map			*map_z;
	t_mlx			*mlx;
}					t_fdf;

int main(int ac, char **av);
void ft_parse_fdf(t_map **map, char *s, int fd);
void ft_init_points(char *s, t_line **l, int *y);
void ft_init_coord(char *str, t_point **p, int *y, int *x);
int ft_init_lines(t_line ***line, char *s, int fd);
void ft_fdf_error(int id);
void ft_get_window(t_fdf **fdf, int h, int w, char *s);
void ft_put_image(t_fdf **fdf, int h, int w);
int ft_key_hook(int key, t_fdf *fdf, t_mlx *mlx);
void ft_draw_map_c(t_fdf **fdf);
void ft_draw_line(t_point p1, t_point p2, t_map m, t_mlx **mlx);
void ft_draw_pixel(t_point p2, t_map map, t_mlx **mlx, int color);
void ft_map_zero(t_mlx **mlx, t_map **map_i, t_map **map_z, t_map **map_c);
void ft_coord_update(t_point **point_x, t_map **map_i, t_map **map_z, t_map **map_c);
void ft_coord_update_z(t_point **point_x, t_map **map_i, t_map **map_z, int i);
void ft_coord_update_c(t_point **point_x, t_map **map_i, t_map **map_c, int i);
void ft_matrix_trans(t_angle **angle, t_map **map_c, int id, float *move);
void ft_matrix_trans_2(t_angle **angle, t_map **map_z, t_map **map_c, int id, float *move);
void ft_init_angle(t_angle **angle);
int	key_exit(void *p);
void ft_check_fdf(t_map *map_i);
int ft_extract_color(char **str, t_point **p, int i);
void ft_get_color(char *color, t_point **p);
int ft_atoi_base(char *s, int num);

#endif //FDF2_FDF2_H

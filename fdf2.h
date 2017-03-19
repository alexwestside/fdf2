
#ifndef FDF2_FDF2_H
#define FDF2_FDF2_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
#include "minilibx/mlx.h"
# include <math.h>
#define HIGHT 400
#define WIDTH 400

typedef struct		s_point
{
	float 			x;
	float 			y;
	float 			z;
	int				r;
	int				g;
	int				b;
	//struct s_point	*next;
	//struct s_point	*below;
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
	t_point			*center;
	//int			len_line;
}					t_mlx;

typedef	struct		s_fdf
{
	t_map			*map;
	t_mlx			*mlx;
}					t_fdf;

int main(int ac, char **av);
void ft_parse_fdf(t_map **map, char *s, int fd);
void ft_init_points(char *s, t_line **l, int *y);
void ft_init_coord(char *str, t_point **p, int *y, int *x);
int ft_init_lines(t_line ***line, char *s, int fd);
void ft_fdf_error(int id);
void ft_count_center(t_mlx **mlx, t_map *map);
void ft_put_image(t_fdf **fdf, int h, int w, char *s);

#endif //FDF2_FDF2_H

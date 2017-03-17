
#ifndef FDF2_FDF2_H
#define FDF2_FDF2_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
//# include <mlx.h>
# include <math.h>

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
	//int			len_line;
}					t_mlx;

typedef	struct		s_fdf
{
	t_map			*map;
	t_mlx			*mlx;
}					t_fdf;

int main(int ac, char **av);

#endif //FDF2_FDF2_H
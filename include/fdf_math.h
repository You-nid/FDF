/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cxb0541 <cxb0541@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/20 21:45:38 by cxb0541          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MATH_H		/*FDF MATH*/
# define FDF_MATH_H

/*Struct*/
typedef struct s_map
{
	int				*x;
	int				y;
	int				width;
	int				*color;
	int				min;
	struct s_map	*next;
}					t_map;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_window;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct s_line
{
	int		x;
	int		y;
	int		color;
}				t_line;

typedef struct s_ham
{
	int		dx;
	int		dy;
	int		err;
	int		e2;
	int		sy;
	int		sx;
	int		x2;
	int		ed;
}			t_ham;


typedef struct s_fdfflags
{
	int		orientation;
	float	focal;
	float	translation_x;
	float	translation_y;
	int		operation;
}			t_fdfflags;


typedef struct s_matrix
{
	t_vector	**vector;
	int			length;
	int			height;
	int			count_x;
	int			count_y;
}				t_matrix;

typedef struct s_fdf
{
	t_line			v0;
	t_line			v1;
	t_ham			ham;
	t_vector		angle;
	float			distance_x;
	float			distance_y;
	int				imagelength;
	int				imageheight;
	double			scale;
	int				margin;
	float			min_x;
	float			min_y;
	t_fdfflags		flags;
	t_matrix		*rotatemat;
}					t_fdf;

/*FUNCTIONS*/
//ANCHOR - AUX
void		ft_exception(char *str);
float		ft_toradian(int angle);
int			ft_toint(float num);

//ANCHOR - Project
void		ft_project(t_window *window, t_fdf *fdf, t_matrix *matrix,
				t_map *map);
void		ft_fdfinit(t_fdf *fdf);

//ANCHOR - Bresenham
void		ft_printheader(t_window *window, t_fdf *fdf);
void		ft_markpoint(t_fdf *fdf, t_matrix *matrix);
void		ft_bresenham(t_window *window, t_fdf *fdf);

//ANCHOR - Matrix
t_matrix	*ft_creatematrix(int dim_x, int dim_y);
void		ft_destroyvector(t_vector ***vector, int size);
void		ft_matrix_map(t_map *map, t_matrix **matrix);

//ANCHOR - AUX Matrix
void		ft_matrixmin(t_matrix *matrix, t_fdf *fdf);

//ANCHOR - Apply
void		ft_apply(t_matrix *matrix, void (*func)(t_vector *, t_fdf *),
				t_fdf *fdf);
void		ft_normalize(t_vector *vector, t_fdf *fdf);
void		ft_increment(t_vector *vector, t_fdf *fdf);
void		ft_translate(t_vector *vector, t_fdf *fdf);
void		ft_topositive(t_vector *vector, t_fdf *fdf);

//ANCHOR - Rotate
void		ft_matrotate(t_vector *vector, t_fdf *fdf);
t_matrix	*ft_get_rotmat(t_fdf *fdf);
void		ft_rotate_y(t_vector *vector, t_fdf *fdf);
void		ft_rotate_z(t_vector *vector, t_fdf *fdf);
void		ft_rotate_x(t_vector *vector, t_fdf *fdf);

//ANCHOR - Plot
void		ft_plot(t_window *window, t_fdf *fdf, t_matrix *matrix);
void		ft_plotmap(t_window *window, t_map *map, t_fdf *fdf,
				t_matrix *matrix);

//ANCHOR - Matrix Operation
t_matrix	*ft_matmult(t_matrix *mat_1, t_matrix *mat_2);
t_matrix	*ft_vecmult(t_vector *vector, t_matrix *matrix);
#endif 					/*END FDF_MATH*/
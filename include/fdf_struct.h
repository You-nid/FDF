/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:33:22 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/04 17:34:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H		/*FDF Struct*/
# define FDF_STRUCT_H

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
	int		color;
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
	int		color;
	int		cy;
}			t_ham;


typedef struct s_fdfflags
{
	int		add_z;
	float	translation_x;
	float	translation_y;
	float	translation_z;
	int		operation;
	int		x_axis;
	int		iso;
	float	focal_distance;
	int		reset;
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
	float			distance_z;
	int				imagelength;
	int				imageheight;
	int				maxlen_x;
	int				maxlen_y;
	double			scale;
	int				margin;
	t_fdfflags		flags;
	t_vector		mid_v;
}					t_fdf;

#endif		/*FDF Struct*/
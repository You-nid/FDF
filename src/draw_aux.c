/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/03 18:17:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Draw Aux
//FIXME - To be deleted
void	ft_printfdf(t_fdf *fdf)
{
	ft_printf("\nParameters:\n");
	ft_printf("\
	*Margin = %i\n\
	*Distance_x = %i\n\
	*Distance_y = %i\n\
	*Imagelength = %i\n\
	*Imageheight = %i\n",
		fdf->margin, fdf->distance_x, fdf->distance_y, fdf->imagelength,
		fdf->imageheight);
}

//ANCHOR - Mark point
void	ft_markpoint(t_fdf *fdf, t_matrix *matrix)
{
	fdf->v0.x = ft_toint(matrix->vector[matrix->count_y][matrix->count_x].x);
	fdf->v0.y = ft_toint(matrix->vector[matrix->count_y][matrix->count_x].y);
	fdf->v0.z = ft_toint(matrix->vector[matrix->count_y][matrix->count_x].z);
	fdf->v0.color = matrix->vector[matrix->count_y][matrix->count_x].color;
	fdf->v1.x
		= ft_toint(matrix->vector[matrix->count_y][matrix->count_x + 1].x);
	fdf->v1.y
		= ft_toint(matrix->vector[matrix->count_y][matrix->count_x + 1].y);
	fdf->v1.z
		= ft_toint(matrix->vector[matrix->count_y][matrix->count_x + 1].z);
	fdf->v1.color
		= matrix->vector[matrix->count_y][matrix->count_x + 1].color;
}

//ANCHOR - Pixel Put
void	ft_pixelput(t_window *window, int dist_x, int dist_y, int color)
{
	char	*dst;

	if (dist_x < 0 || dist_y < 0)
		return ;
	dst = window->addr
		+ (window->size_line * dist_y + dist_x * (window->bpp / 8));
	if (dst != NULL)
		*(unsigned int *)dst = mlx_get_color_value(window->mlx, color);
}

//ANCHOR - Write to window
void	ft_printheader(t_window *window, t_fdf *fdf)
{
	mlx_string_put(window->mlx, window->win, 1, 1, 0xFFFF00,
		ft_strjoin("Width: ", ft_itoa(fdf->imagelength / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 15, 0xFFFF00,
		ft_strjoin("Height: ", ft_itoa(fdf->imageheight / fdf->scale)));
	mlx_string_put(window->mlx, window->win, 1, 30, 0xFFFF00,
		ft_strjoin("Scale: ", ft_itoa((int)fdf->scale)));
}

//ANCHOR - Draw Net
void	ft_draw_xy(t_window *window, t_fdf *fdf)
{
	fdf->ham.dx = abs(fdf->v1.x - fdf->v0.x);
	fdf->ham.dy = abs(fdf->v1.y - fdf->v0.y);
	if (fdf->v0.x < fdf->v1.x)
		fdf->ham.sx = 1;
	else
		fdf->ham.sx = -1;
	if (fdf->v0.y < fdf->v1.y)
		fdf->ham.sy = 1;
	else
		fdf->ham.sy = -1;
	fdf->ham.err = fdf->ham.dx - fdf->ham.dy;
	fdf->ham.ed = fdf->ham.dx + fdf->ham.dy;
	if (fdf->ham.ed == 0)
		fdf->ham.ed = 1;
	else
		fdf->ham.ed = sqrt((float)pow(fdf->ham.dx, 2) + (float)pow(fdf->ham.dy, 2));
	while (1)
	{
		if (fdf->v0.x < fdf->imagelength
			&& fdf->v0.y < fdf->imageheight)
		{
			ft_pixelput(window, fdf->v0.x, fdf->v0.y, fdf->v0.color);
			ft_pixelput(window, fdf->v0.y, fdf->v0.x, fdf->v0.color);
		}
		fdf->ham.e2 = fdf->ham.err;
		fdf->ham.x2 = fdf->v0.x;
		if (fdf->v0.x == fdf->v1.x && fdf->v0.y == fdf->v1.y)
			break ;
		if (fdf->ham.e2*2 >= -fdf->ham.dx)
		{
			if (fdf->ham.e2+fdf->ham.dy < fdf->ham.ed)
				ft_pixelput(window, fdf->v0.x, fdf->v0.y + fdf->ham.sy, fdf->v0.color);
			fdf->ham.err -= fdf->ham.dy;
			fdf->v0.x += fdf->ham.sx;
		}
		if (fdf->ham.e2*2 <= fdf->ham.dy)
		{
			if (fdf->ham.dx - fdf->ham.e2 < fdf->ham.ed)
				ft_pixelput(window, fdf->ham.x2 + fdf->ham.sx, fdf->v0.y, fdf->v0.color);
			fdf->ham.err += fdf->ham.dx;
			fdf->v0.y += fdf->ham.sy;
		}
	}
}

//!SECTION

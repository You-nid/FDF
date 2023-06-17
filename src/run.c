/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:07:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/06/17 16:22:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Run program

//ANCHOR - Run Window
void	ft_run(t_window *window, t_map *map, int height)
{
	t_fdf		*fdf;
	t_matrix	*matrix;

	if (!map || !window)
		return ;
	fdf = ft_initstructs(window, map, height);
	matrix = ft_creatematrix(fdf->imagelength / fdf->scale,
			fdf->imageheight / fdf->scale);
	if (!matrix)
		return ;
	ft_plotmap(window, map, fdf, matrix);
	ft_mousehooks(window);
	ft_keyhooks(window);
	mlx_loop(window->mlx);
	free(fdf);
}
//!SECTION

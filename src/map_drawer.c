/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:12:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/05/03 20:22:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map Drawer
//ANCHOR - Draw Map
void	ft_drawmap(t_window *window, t_map *map)
{
	window->img = mlx_new_image(window->mlx, map->size, map->size);
	if (!window->img)
		return ;
	mlx_get_data_addr(window->img, &window->bpp,
		&window->size, &window->endian);
}

//!SECTION
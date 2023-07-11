/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:46:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/11 19:56:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Map AUX
//ANCHOR - Get color
static int	ft_getcolor(char *str, t_map **map, int index)
{
	int		pos;
	char	*string;

	if (!str || !(*map))
		return (FALSE);
	pos = ft_charpos(str, ',');
	(*map)->color[index] = ft_atoibase((ft_strchr(str, ',') + 1), 16);
	string = ft_substr(str, 0, pos);
	if (ft_isdigitstr(string) == TRUE)
		(*map)->x[index] = ft_atoi(string);
	else
	{
		free(string);
		return (FALSE);
	}
	free(string);
	return (TRUE);
}

//ANCHOR - From string array to integer array
int	ft_readarr(char **str, t_map **map)
{
	int	index;

	index = 0;
	if (!str || *str == NULL)
		return (FALSE);
	(*map)->x = ft_createarray(ft_strlen_arr(str));
	(*map)->color = ft_createarray(ft_strlen_arr(str));
	if (!(*map)->color || !(*map)->x)
		ft_exception("Failed to create int array");
	while (str[index])
	{
		if (ft_findchr(str[index], ',') == TRUE)
		{
			if (ft_getcolor(str[index], &(*map), index) != TRUE)
				ft_exception("Invalid Map");
		}
		else if (ft_isdigitstr(str[index]) == TRUE)
			(*map)->x[index] = ft_atoi(str[index]);
		else
			ft_exception("Invalid Map");
		++index;
	}
	(*map)->width = index;
	return (TRUE);
}

//ANCHOR - Color Flood
void	ft_colorflood(int **array, int size)
{
	int	index;

	index = 0;
	if (!*array || !size || size == 0)
		return ;
	while (index < size)
	{
		if ((*array)[index] == 0)
			(*array)[index] = WHITE;
		index++;
	}
}

//!SECTION

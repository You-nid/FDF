/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:05:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/26 20:23:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int ac, char **av)
{
	t_map		*map;
	t_window	*window;

	if (ac == 2)
	{
		map = ft_readmap(av);
		if (!map)
		{
			ft_putstr_fd("Error\n", 2);
			return (EXIT_FAILURE);
		}
		window = ft_window(CREATE);
		window = ft_window(DESTROY);
		ft_deletemap(&map);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

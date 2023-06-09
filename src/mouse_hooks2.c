/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:31:30 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/10 20:41:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//SECTION - Mouse Hooks
//ANCHOR - Close Window
int	ft_closewindow(void *param)
{
	t_params	*params;

	params = (t_params *)param;
	params->window->freed = TRUE;
	ft_freeall(params);
	exit (EXIT_SUCCESS);
}

//ANCHOR - Mouse Magnify
static void	ft_mousemagnify(int button, t_params *params)
{
	if (button == 4)
		params->fdf->flags.focal_distance -= 1;
	else if (button == 5)
		params->fdf->flags.focal_distance += 1;
}

//ANCHOR - Mouse Button
int	ft_mousebutton(int button, int x, int y, void *param)
{
	t_params	*params;

	params = (t_params *)param;
	if (button == 4 || button == 5)
		ft_mousemagnify(button, params);
	if (button == 1)
		params->hook->button_1_press = TRUE;
	if (button == 2)
	{
		params->hook->button_2_press = TRUE;
		params->hook->x = x;
		params->hook->y = y;
	}
	return (TRUE);
}

//!SECTION
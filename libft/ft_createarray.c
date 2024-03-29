/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:59:06 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 15:31:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	*ft_createarray(int size)
{
	long	*array;

	if (!size)
		return ((long *)-1);
	if (size == 0)
		size = 1;
	array = ft_calloc(size, sizeof(long));
	if (!array)
		return ((long *)-1);
	return (array);
}

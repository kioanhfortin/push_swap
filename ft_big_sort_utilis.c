/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_utilis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:49:15 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/20 11:51:41 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_pos(t_ps *tab_a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < tab_a->size)
	{
		if (tab_a->index[0] > tab_a->index[i])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

int	ft_max_position(t_ps *tab_a)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (i < tab_a->size)
	{
		if (tab_a->index[flag] < tab_a->index[i])
			flag = i;
		i++;
	}
	return (flag + 1);
}

int	ft_max_pos(t_ps *tab_a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < tab_a->size)
	{
		if (tab_a->index[0] < tab_a->index[i])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

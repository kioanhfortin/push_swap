/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:11:19 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/20 11:50:39 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_clean(t_ps *tab_a, t_ps *tab_b, int mid)
{
	int	i;

	i = 0;
	while (tab_a->size > 0)
	{
		if (tab_b->size == mid)
			break ;
		while (tab_b->size < (mid / 10) * i)
		{
			if (tab_b->size == mid)
				break ;
			if (tab_a->index[0] <= (mid / 10) * i)
				push_b(tab_a, tab_b);
			else
				rot_a(tab_a, 0);
		}
		i += 2;
	}
}

void	ft_sort_100(t_ps *tab_a, t_ps *tab_b)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	ft_first_clean(tab_a, tab_b, tab_a->size);
	while (i <= 1000)
	{
		if (tab_b->size == 10 && tab_a->size_arg == 100)
			break ;
		if (ft_max_position(tab_b) <= tab_b->size / 2)
			if (tab_a->j <= 40)
				ft_tchek_top(tab_a, tab_b);
		if (ft_max_position(tab_b) > tab_b->size / 2)
		{
			if (tab_b->index[tab_b->size - 1] > 10)
				ft_tchek_bottom(tab_a, tab_b);
			tab_a->j = 0;
		}
		i++;
	}
	ft_sort_10_b(tab_a, tab_b, 0);
}

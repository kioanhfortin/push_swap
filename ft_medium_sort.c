/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:57:48 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/13 12:05:52 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_10_b_part2(t_ps *tab_a, t_ps *tab_b, int flag)
{
	if (flag == 0)
	{
		ft_sort_3(tab_b, 0);
		rrot_b(tab_b);
		swap_sa_sb(*tab_b, 'b');
		rot_b(tab_b);
	}
	while (tab_b->size != 0)
		push_a(tab_a, tab_b);
}

void	ft_sort_10_b(t_ps *tab_a, t_ps *tab_b, int flag)
{
	int	i;
	int	k;
	int	mid;

	i = 0;
	k = 2;
	mid = tab_a->size_arg;
	while (tab_a->size < (mid / k))
	{
		if (ft_max_pos(tab_b) == 1)
			push_a(tab_a, tab_b);
		else
			rot_b(tab_b);
	}
	while (tab_b->size > 3)
	{
		if (ft_max_pos(tab_b) == 1)
			push_a(tab_a, tab_b);
		else
			rot_b(tab_b);
	}
	ft_sort_10_b_part2(tab_a, tab_b, flag);
}

void	ft_sort_10_part2(t_ps *tab_a, t_ps *tab_b, int mid)
{
	int	i;

	i = 3;
	ft_sort_3(tab_a, 1);
	while (i <= 6)
	{
		if (ft_max_pos(tab_b) == 1 || tab_b->size == 1)
		{
			push_a(tab_a, tab_b);
			i++;
		}
		if (tab_b->size == 3 && ft_check_double_order(*tab_a) != 0)
		{
			ft_sort_3(tab_b, 1);
			rrot_b(tab_b);
			swap_sa_sb(*tab_b, 'b');
			rot_b(tab_b);
		}
		if (tab_b->index[0] < mid / 2 + 10)
			rrot_b(tab_b);
		if (tab_b->index[0] < tab_b->index[1])
			swap_sa_sb(*tab_b, 'b');
		if (ft_max_pos(tab_b) == 1 || tab_b->size == 1)
			push_a(tab_a, tab_b);
	}
}

void	ft_sort_10(t_ps *tab_a, t_ps *tab_b)
{
	int	k;
	int	mid;

	k = 2;
	mid = tab_a->size_arg;
	while (tab_b->size < (mid / k))
	{
		if (ft_min_pos(tab_a) == 1 && (tab_a->index[0] <= (mid / k)))
			push_b(tab_a, tab_b);
		else
			rot_a(tab_a, 0);
	}
	while (tab_a->size > 3)
	{
		if (ft_min_pos(tab_a) == 1)
			push_b(tab_a, tab_b);
		else
			rot_a(tab_a, 0);
	}
	ft_sort_10_part2(tab_a, tab_b, mid);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:07:31 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/20 11:50:14 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_clean_500_b(t_ps *tab_a, t_ps *tab_b, int mid)
{
	int	j;
	int	i;

	j = 10;
	i = 50;
	ft_first_clean_2(tab_a, tab_b, 100);
	while (tab_a->size > 1)
	{
		if (tab_a->size == 1)
			break ;
		while (tab_b->size < (mid / i) * j)
		{
			if (tab_a->size == 1)
				break ;
			if (tab_a->index[0] == tab_a->size_arg)
				rot_a(tab_a, 0);
			if (tab_a->index[0] <= (mid / i) * j)
				push_b(tab_a, tab_b);
			else
				rot_a(tab_a, 0);
		}
		j += 3;
	}
}

void	ft_tchek_top(t_ps *tab_a, t_ps *tab_b)
{
	if (ft_max_pos(tab_b) == 1)
		push_a(tab_a, tab_b);
	else
	{
		rot_b(tab_b);
		tab_a->j += 1;
	}
}

void	ft_tchek_bottom(t_ps *tab_a, t_ps *tab_b)
{
	rrot_b(tab_b);
	if (ft_max_pos(tab_b) == 1)
		push_a(tab_a, tab_b);
}

void	ft_sort_500_b_part2(t_ps *tab_a, t_ps *tab_b)
{
	int	i;

	i = 0;
	while (i <= 1000)
	{
		if (tab_b->size == 10)
			break ;
		if (ft_max_position(tab_b) <= tab_b->size / 2)
			if (tab_a->j <= 20)
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

void	ft_sort_500_b(t_ps *tab_a, t_ps *tab_b)
{
	int	mid;
	int	flag;
	int	i;

	mid = 2;
	flag = 0;
	i = 0;
	ft_first_clean_500_b(tab_a, tab_b, tab_a->size_arg);
	while (i <= 10000)
	{
		if (tab_b->size == 100)
			break ;
		if (ft_max_position(tab_b) <= tab_b->size / mid)
			if (tab_a->j <= 30)
				ft_tchek_top(tab_a, tab_b);
		if (ft_max_position(tab_b) > tab_b->size / mid)
		{
			if (tab_b->index[tab_b->size - 1] > 100)
				ft_tchek_bottom(tab_a, tab_b);
			tab_a->j = 0;
		}
		i++;
	}
	ft_sort_500_b_part2(tab_a, tab_b);
}

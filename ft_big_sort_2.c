/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:59:18 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/20 11:50:32 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_clean_2(t_ps *tab_a, t_ps *tab_b, int mid)
{
	int	i;

	i = 2;
	while (tab_a->size >= 0)
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

void	ft_first_clean_500(t_ps *tab_a, t_ps *tab_b, int mid)
{
	int	j;
	int	i;

	j = 10;
	i = 50;
	ft_first_clean_2(tab_a, tab_b, 100);
	while (tab_b->size < mid - 10)
	{
		while (tab_b->size < (mid / i) * j)
		{
			if (tab_a->index[0] <= (mid / i) * j)
				push_b(tab_a, tab_b);
			else
				rot_a(tab_a, 0);
		}
		j += 3;
	}
}

void	ft_sort_500_part2(t_ps *tab_a, t_ps *tab_b)
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

void	ft_sort_500(t_ps *tab_a, t_ps *tab_b)
{
	int	mid;
	int	flag;
	int	i;

	mid = 2;
	flag = 0;
	i = 0;
	ft_first_clean_500(tab_a, tab_b, tab_a->size_arg);
	ft_sort_10(tab_a, tab_b);
	while (i <= 10000)
	{
		if (tab_b->size == 100)
			break ;
		if (ft_max_position(tab_b) <= tab_b->size / mid)
			if (tab_a->j <= 50)
				ft_tchek_top(tab_a, tab_b);
		if (ft_max_position(tab_b) > tab_b->size / mid)
		{
			if (tab_b->index[tab_b->size - 1] > 100)
				ft_tchek_bottom(tab_a, tab_b);
			tab_a->j = 0;
		}
		i++;
	}
	ft_sort_500_part2(tab_a, tab_b);
}

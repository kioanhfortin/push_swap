/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:11:24 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/13 11:38:03 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_ps *tab_a)
{
	if (tab_a->index[0] > tab_a->index[1])
		swap_sa_sb(*tab_a, 'a');
}

void	ft_sort_3_part1(t_ps *tab_a, int flag)
{
	if (((tab_a->index[0] - tab_a->index[1]) > 0) && ((tab_a->index[1]
				- tab_a->index[2]) < 0) && ((tab_a->index[0]
				- tab_a->index[2]) > 0))
	{
		if (flag == 1)
			rot_a(tab_a, 0);
		else
			rot_b(tab_a);
	}
	if (((tab_a->index[0] - tab_a->index[1]) > 0) && ((tab_a->index[1]
				- tab_a->index[2]) < 0))
	{
		if (flag == 1)
			swap_sa_sb(*tab_a, 'a');
		else
			swap_sa_sb(*tab_a, 'b');
	}
}

void	ft_sort_3_part2(t_ps *tab_a, int flag)
{
	if (((tab_a->index[0] - tab_a->index[1]) < 0) && ((tab_a->index[1]
				- tab_a->index[2]) > 0) && ((tab_a->index[0]
				- tab_a->index[2]) < 0))
	{
		if (flag == 1)
		{
			swap_sa_sb(*tab_a, 'a');
			rot_a(tab_a, 0);
		}
		else
		{
			swap_sa_sb(*tab_a, 'b');
			rot_a(tab_a, 1);
		}
	}
	if (((tab_a->index[0] - tab_a->index[1]) < 0) && ((tab_a->index[1]
				- tab_a->index[2]) > 0) && ((tab_a->index[0]
				- tab_a->index[2]) > 0))
	{
		if (flag == 1)
			rrot_a(tab_a, 0);
		else
			rrot_a(tab_a, 1);
	}
}

void	ft_sort_3(t_ps *tab_a, int flag)
{
	if (tab_a->size != 0)
	{
		if (((tab_a->index[0] - tab_a->index[1]) > 0) && ((tab_a->index[1]
					- tab_a->index[2]) > 0) && ((tab_a->index[0]
					- tab_a->index[2]) > 0))
		{
			if (flag == 1)
			{
				swap_sa_sb(*tab_a, 'a');
				rrot_a(tab_a, 0);
			}
			else
			{
				swap_sa_sb(*tab_a, 'b');
				rrot_a(tab_a, 1);
			}
		}
		ft_sort_3_part1(tab_a, flag);
		ft_sort_3_part2(tab_a, flag);
	}
}

void	ft_sort_5(t_ps *tab_a, t_ps *tab_b)
{
	int	i;

	i = 0;
	while (tab_b->size < 2)
	{
		if (tab_a->index[0] < 3)
			push_b(tab_a, tab_b);
		else
			rot_a(tab_a, 0);
	}
	if (tab_a->size == 3)
		ft_sort_3(tab_a, 1);
	if (tab_a->size < 3 && tab_a->index[0] > tab_a->index[1])
		swap_sa_sb(*tab_a, 'a');
	if (tab_b->index[0] < tab_b->index[1])
		swap_sa_sb(*tab_b, 'b');
	while (i <= tab_b->size)
	{
		push_a(tab_a, tab_b);
		i++;
	}
}

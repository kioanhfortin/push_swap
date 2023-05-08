/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:44:44 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/13 11:41:39 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa_sb(t_ps tab_a, int flag)
{
	int	temp;

	temp = tab_a.index[0];
	tab_a.index[0] = tab_a.index[1];
	tab_a.index[1] = temp;
	if (flag == 'a')
		write(1, "sa\n", 3);
	else if (flag == 'b')
		write(1, "sb\n", 3);
}

void	push_b_part2(t_ps *tab_a, t_ps *tab_b, int temp)
{
	int	i;

	i = 0;
	while (i < tab_a->size - 1)
	{
		tab_a->index[i] = tab_a->index[i + 1];
		i++;
	}
	tab_b->index[0] = temp;
	tab_a->index[tab_a->size - 1] = 0;
	tab_a->size -= 1;
	tab_b->size += 1;
	tab_b->first_p = ft_max_index(tab_b, 1);
	tab_a->first_p = ft_max_index(tab_a, 1);
	write(1, "pb\n", 3);
	tab_b->max_repeat += 1;
}

void	push_b(t_ps *tab_a, t_ps *tab_b)
{
	int	i;
	int	temp;

	temp = tab_a->index[0];
	i = 0;
	if (ft_tab_empty(tab_b) == 1)
		return ;
	i = tab_b->size;
	while (i > 0)
	{
		tab_b->index[i] = tab_b->index[i - 1];
		i--;
	}
	push_b_part2(tab_a, tab_b, temp);
}

void	push_a_part2(t_ps *tab_a, t_ps *tab_b, int temp)
{
	int	i;

	i = 0;
	while (i < tab_b->size - 1)
	{
		tab_b->index[i] = tab_b->index[i + 1];
		i++;
	}
	tab_a->index[0] = temp;
	tab_b->index[tab_b->size - 1] = 0;
	tab_b->size -= 1;
	tab_a->size += 1;
	tab_b->first_p = ft_max_index(tab_b, 1);
	tab_a->first_p = ft_max_index(tab_a, 1);
	write(1, "pa\n", 3);
	tab_a->max_repeat += 1;
}

void	push_a(t_ps *tab_a, t_ps *tab_b)
{
	int	i;
	int	temp;

	temp = tab_b->index[0];
	i = 0;
	if (ft_tab_empty(tab_a) == 1)
		return ;
	i = tab_a->size;
	while (i > 0)
	{
		tab_a->index[i] = tab_a->index[i - 1];
		i--;
	}
	push_a_part2(tab_a, tab_b, temp);
}

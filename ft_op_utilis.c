/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:16:56 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/13 11:25:22 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_index(t_ps *tab, int flag)
{
	if (flag == 1 && tab->first_p == tab->size)
		tab->first_p = 0;
	if (flag == 0 && tab->first_p < 0)
		tab->first_p = tab->size - 1;
	return (tab->first_p);
}

int	ft_double_zero(t_ps *tab_a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < tab_a->size_arg)
	{
		if (tab_a->index[i] == 0)
			flag = 1;
		if (tab_a->index[i] == 0 && flag == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_tab_empty(t_ps *tab_a)
{
	int	i;

	i = 0;
	if (tab_a->size == tab_a->size_arg)
	{
		tab_a->max_repeat = 0;
		return (1);
	}
	return (0);
}

void	rrot_a(t_ps *tab_a, int flag)
{
	int	i;
	int	temp;

	i = tab_a->size - 2;
	temp = tab_a->index[tab_a->size - 1];
	if (tab_a->size == 0)
		return ;
	while (i >= 0)
	{
		tab_a->index[i + 1] = tab_a->index[i];
		i--;
	}
	tab_a->index[0] = temp;
	if (tab_a->size != 1)
	{
		if (flag == 0)
			write(1, "rra\n", 4);
		if (flag == 1)
			write(1, "rrb\n", 4);
		if (flag == 2)
			write(1, "rrr\n", 4);
	}
}

void	swap_ss(t_ps tab_a, t_ps tab_b)
{
	swap_sa_sb(tab_a, 'a');
	swap_sa_sb(tab_b, 'b');
	write(1, "ss\n", 3);
}

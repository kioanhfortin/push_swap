/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:18:32 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/13 11:24:54 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrot_b(t_ps *tab_b)
{
	rrot_a(tab_b, 1);
}

void	rrot_ab(t_ps *tab_a, t_ps *tab_b)
{
	rrot_a(tab_a, 2);
	rrot_a(tab_b, -1);
}

void	rot_a(t_ps *tab_a, int flag)
{
	int	i;
	int	temp;

	i = 0;
	temp = tab_a->index[0];
	if (tab_a->size == 0)
		return ;
	while (i < tab_a->size)
	{
		tab_a->index[i] = tab_a->index[i + 1];
		i++;
	}
	tab_a->index[tab_a->size - 1] = temp;
	if (tab_a->size != 1)
	{
		if (flag == 0)
			write(1, "ra\n", 3);
		if (flag == 1)
			write(1, "rb\n", 3);
		if (flag == 2)
			write(1, "rr\n", 3);
	}
}

void	rot_b(t_ps *tab_b)
{
	rot_a(tab_b, 1);
}

void	rot_ab(t_ps *tab_a, t_ps *tab_b)
{
	rot_a(tab_a, 2);
	rot_a(tab_b, -1);
}

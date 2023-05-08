/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:15:03 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/20 15:13:21 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab2(char **tab)
{
	if (tab)
	{
		ft_free_tab(tab);
		free(tab);
	}
}

int	*ft_init_b(t_ps tab)
{
	int	*b;

	b = ft_calloc(sizeof(int), tab.size_arg + 1);
	if (!b)
		return (0);
	return (b);
}

void	ft_init_struct(t_ps *tab_a)
{
	tab_a->tab = 0;
	tab_a->index = 0;
	tab_a->size = 0;
	tab_a->size_arg = 0;
	tab_a->first_p = 0;
	tab_a->max_repeat = 0;
	tab_a->nbr_ite = 0;
	tab_a->j = 0;
	tab_a->flag = 0;
}

void	ft_init_all(int argc, char **argv, t_ps *tab_a, t_ps *tab_b)
{
	ft_init_struct(tab_a);
	ft_init_struct(tab_b);
	ft_parse_arg(argc, argv, tab_a, tab_b);
	tab_a->size_arg = tab_a->size;
	tab_b->size_arg = tab_a->size;
	tab_b->tab = ft_init_b(*tab_b);
	tab_a->index = ft_init_b(*tab_a);
	tab_b->index = ft_init_b(*tab_b);
}

int	main(int argc, char **argv)
{
	t_ps	tab_a;
	t_ps	tab_b;

	ft_init_all(argc, argv, &tab_a, &tab_b);
	ft_indexation(&tab_a);
	if (tab_a.size_arg <= 2)
		ft_sort_2(&tab_a);
	else if (tab_a.size_arg == 3)
		ft_sort_3(&tab_a, 1);
	else if (tab_a.size_arg <= 5)
		ft_sort_5(&tab_a, &tab_b);
	else if (tab_a.size_arg <= 10)
		ft_sort_10(&tab_a, &tab_b);
	else if (tab_a.size_arg <= 100)
		ft_sort_100(&tab_a, &tab_b);
	else if (tab_a.size_arg == 500)
		ft_sort_500(&tab_a, &tab_b);
	else if (tab_a.size_arg < 500)
		ft_sort_500_b(&tab_a, &tab_b);
	else if (tab_a.size_arg > 500)
		ft_sort_500_b(&tab_a, &tab_b);
	ft_free(&tab_a, &tab_b);
}

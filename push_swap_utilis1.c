/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:01:31 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/15 11:11:40 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_ps *tab_a, t_ps *tab_b)
{
	if (tab_a->tab != 0)
		free(tab_a->tab);
	if (tab_b->tab != 0)
		free(tab_b->tab);
	if (tab_a->index != 0)
		free(tab_a->index);
	if (tab_b->index != 0)
		free(tab_b->index);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	else
		return (0);
}

void	ft_write_error(void *tab)
{
	if (tab)
		free(tab);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

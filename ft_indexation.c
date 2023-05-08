/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:08:14 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/17 11:33:16 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*int_dup(t_ps *tab_a)
{
	int	*temp;
	int	i;

	i = 0;
	temp = ft_calloc(sizeof(int), tab_a->size_arg + 1);
	while (i < tab_a->size_arg)
	{
		temp[i] = tab_a->tab[i];
		i++;
	}
	return (temp);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size - i)
		{
			if (tab[j] < tab[j - 1])
			{
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_indexation(t_ps *tab_a)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = int_dup(tab_a);
	ft_sort_int_tab(temp, tab_a->size_arg);
	while (i < tab_a->size_arg)
	{
		j = 0;
		while (j < tab_a->size_arg)
		{
			if (tab_a->tab[i] == temp[j])
				tab_a->index[i] = j + 1;
			j++;
		}
		i++;
	}
	free(temp);
}

int	ft_space_arg(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_error_long(char **tab, int i, int *tab_int)
{
	if (ft_atol(tab[i]) > 2147483647 || atol(tab[i]) < -2147483648)
	{
		ft_free_tab2(tab);
		ft_write_error(tab_int);
	}
}

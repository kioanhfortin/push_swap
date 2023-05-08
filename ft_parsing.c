/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:01:41 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/17 17:17:33 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double_order(t_ps tab_a)
{
	int	i;
	int	j;
	int	flag1;
	int	flag2;

	i = -1;
	flag1 = 0;
	flag2 = 0;
	while (++i < tab_a.size)
	{
		j = i + 1;
		while (j < tab_a.size)
		{
			if (tab_a.tab[i] > tab_a.tab[j])
				flag1 = 1;
			if (tab_a.tab[i] == tab_a.tab[j])
				flag2 = 1;
			j++;
		}
	}
	if (flag2 == 1)
		return (1);
	if (flag1 == 0)
		return (-1);
	return (0);
}

void	ft_error2(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char	*ft_error(char *arg, t_ps tab_a)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	k = NULL;
	while (arg[i] != '\0')
	{
		if ((arg[i] == '-' || arg[i] == '+') && tab_a.flag == 0)
			tab_a.flag = 1;
		if ((arg[i] == '-' || arg[i] == '+') && tab_a.flag == 1
			&& ft_isdigit(arg[i + 1]) == 0)
			ft_error2();
		if (!(arg[i] >= '0' && arg[i] <= '9') && ft_isspace(arg[i]) == 0
			&& !(arg[i] == '-' || arg[i] == '+'))
			ft_error2();
		i++;
	}
	return (arg);
}

void	ft_parse_arg_part1(int argc, char **argv, t_ps *tab_a, t_ps *tab_b)
{
	int	i;

	i = 0;
	(void)tab_b;
	if (argc > 2)
	{
		tab_a->size = argc - 1;
		tab_a->tab = ft_calloc(sizeof(int), argc - 1);
		if (!tab_a->tab)
			exit(0);
		while (i < argc - 1)
		{
			if (ft_space_arg(argv[i]) == 1)
				ft_write_error(tab_a->tab);
			if (ft_error(argv[i + 1], *tab_a) == NULL)
				ft_write_error(tab_a->tab);
			tab_a->tab[i] = ft_atol(argv[i + 1]);
			if (ft_atol(argv[i + 1]) > 2147483647
				|| ft_atol(argv[i + 1]) < -2147483648)
				ft_write_error(tab_a->tab);
			i++;
		}
	}
	if (ft_check_double_order(*tab_a) == 1)
		ft_write_error(tab_a->tab);
}

void	ft_parse_arg(int argc, char **argv, t_ps *tab_a, t_ps *tab_b)
{
	if (argc < 2)
		return ;
	if (argc == 2)
	{
		tab_a->size = ft_count_word(argv[1], "\t\n\r\v\f ");
		if (ft_error(argv[1], *tab_a) == NULL)
			ft_write_error(tab_a->tab);
		tab_a->tab = ft_split(argv[1], "\t\n\r\v\f ");
	}
	ft_parse_arg_part1(argc, argv, tab_a, tab_b);
	if (ft_check_double_order(*tab_a) == -1)
	{
		ft_free(tab_a, tab_b);
		exit(0);
	}
}

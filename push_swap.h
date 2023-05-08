/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:15:41 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/20 11:52:00 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	int	*tab;
	int	*index;
	int	size;
	int	size_arg;
	int	first_p;
	int	max_repeat;
	int	nbr_ite;
	int	j;
	int	flag;
}		t_ps;

int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		*ft_split(char *str, char *charset);
int		ft_count_word(char *str, char *charset);
long	ft_atol(char *str);
char	*ft_error(char *arg, t_ps tab_a);
void	ft_error2(void);
void	ft_write_error(void *tab);
int		ft_isspace(char c);
int		ft_space_arg(char *str);
void	ft_init_all(int argc, char **argv, t_ps *tab_a, t_ps *tab_b);
void	ft_init_struct(t_ps *tab_a);
int		*ft_init_b(t_ps tab);
void	ft_parse_arg(int argc, char **argv, t_ps *tab_a, t_ps *tab_b);
int		ft_check_double_order(t_ps tab_a);
int		ft_max_index(t_ps *tab, int flag);
int		*int_dup(t_ps *tab_a);
int		ft_tab_empty(t_ps *tab_a);
void	swap_sa_sb(t_ps tab_a, int flag);
void	swap_ss(t_ps tab_a, t_ps tab_b);
void	push_a(t_ps *tab_a, t_ps *tab_b);
void	push_a_part2(t_ps *tab_a, t_ps *tab_b, int temp);
void	push_b(t_ps *tab_a, t_ps *tab_b);
void	push_b_part2(t_ps *tab_a, t_ps *tab_b, int temp);
void	rot_a(t_ps *tab_a, int flag);
void	rot_b(t_ps *tab_b);
void	rot_ab(t_ps *tab_a, t_ps *tab_b);
void	rrot_a(t_ps *tab_a, int flag);
void	rrot_b(t_ps *tab_b);
void	rrot_ab(t_ps *tab_a, t_ps *tab_b);
void	ft_sort_2(t_ps *tab_a);
void	ft_sort_3_part1(t_ps *tab_a, int flag);
void	ft_sort_3_part2(t_ps *tab_a, int flag);
void	ft_sort_3(t_ps *tab_a, int flag);
void	ft_indexation(t_ps *tab_a);
void	ft_error_long(char **tab, int i, int *tab_int);
void	ft_sort_5(t_ps *tab_a, t_ps *tab_b);
int		ft_min_pos(t_ps *tab_a);
int		ft_max_pos(t_ps *tab_a);
int		ft_max_pos2(t_ps *tab_a);
int		ft_max_position(t_ps *tab_a);
int		ft_most_dist(t_ps *tab_b);
void	ft_sort_10(t_ps *tab_a, t_ps *tab_b);
void	ft_sort_10_part2(t_ps *tab_a, t_ps *tab_b, int mid);
void	ft_sort_10_b(t_ps *tab_a, t_ps *tab_b, int flag);
void	ft_sort_10_b_part2(t_ps *tab_a, t_ps *tab_b, int flag);
void	ft_tchek_top(t_ps *tab_a, t_ps *tab_b);
void	ft_tchek_bottom(t_ps *tab_a, t_ps *tab_b);
void	ft_first_clean(t_ps *tab_a, t_ps *tab_b, int mid);
void	ft_sort_100(t_ps *tab_a, t_ps *tab_b);
void	ft_first_clean_2(t_ps *tab_a, t_ps *tab_b, int mid);
void	ft_first_clean_500_b(t_ps *tab_a, t_ps *tab_b, int mid);
void	ft_sort_500_b_part2(t_ps *tab_a, t_ps *tab_b);
void	ft_sort_500_b(t_ps *tab_a, t_ps *tab_b);
void	ft_first_clean_500(t_ps *tab_a, t_ps *tab_b, int mid);
void	ft_sort_500_part2(t_ps *tab_a, t_ps *tab_b);
void	ft_sort_500(t_ps *tab_a, t_ps *tab_b);
void	ft_free_tab(char **tab);
void	ft_free_tab2(char **tab);
void	ft_free_tab_int(t_ps *tab_a);
void	ft_free(t_ps *tab_a, t_ps *tab_b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 08:19:46 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/01 08:19:55 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

# define ASCENDING 0
# define DESCENDING 1
# define FLG 0
# define STACK 1

//Misc

void	ft_push_swap(char **argv);
void	ft_error(int *stack);
void	ft_check_repeat(int *stack, int size);
int		ft_ps_atoi(char *str, int *stack);
int		ft_ps_strlen(char **argv);
int		ft_check_sorted(int *stack, int size, int order);

//Operations

void	ft_sa(t_stacks *stack, int print);
void	ft_sb(t_stacks *stack, int print);
void	ft_ss(t_stacks *stack, int print);
void	ft_ra(t_stacks *stack, int print);
void	ft_rb(t_stacks *stack, int print);
void	ft_rr(t_stacks *stack, int print);
void	ft_rra(t_stacks *stack, int print);
void	ft_rrb(t_stacks *stack, int print);
void	ft_rrr(t_stacks *stack, int print);
void	ft_pa(t_stacks *stack, int print);
void	ft_pb(t_stacks *stack, int print);

//Sortage

void	ft_sort_tmp(int *temp_stack, int size);
void	ft_sort_three_a(t_stacks *s);
int		ft_sort(t_stacks *stack, int size);
int		ft_push(t_stacks *stack, int len, int operation);

//Quicksort

void	ft_quicksort_3(t_stacks *stack, int len);
int		ft_sort_small_b(t_stacks *s, int len);
int		ft_get_mediane(int *pivot, int *stack, int size);
int		ft_quicksort_a(t_stacks *stack, int len, int count);
int		ft_quicksort_b(t_stacks *stack, int len, int count);

//Bonus

int		*ft_check_errors(char **argv);
int		ft_check_opt(char *opt, t_stacks *stack);
int		ft_strcmp(char *s1, char *s2);
void	ft_checker(t_stacks *stack);
void	ft_checker_instructions(t_stacks *stack);
void	ft_checker_start(t_stacks *stack);
void	ft_opt(t_stacks *stack, char *opt);
void	ft_print_stacks(t_stacks *stack);

#endif

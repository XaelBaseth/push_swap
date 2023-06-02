/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:12:17 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/01 11:12:19 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "../libft/inc/ft_printf.h"

/*	This function swaps the first two elements of stack a. */
void	ft_sa(t_stacks *stack, int print)
{
	int	temp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few number in Stack A.\n");
		return ;
	}
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	if (print == FLG)
		ft_printf("sa\n");
}

/*	This function swaps the first two elements of stack b. */
void	ft_sb(t_stacks *stack, int print)
{
	int	temp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few number in Stack B.\n");
		return ;
	}
	temp = 0;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (print == FLG)
		ft_printf("sb\n");
}

/*	This function swaps the first two elements of stacks a and b. */
void	ft_ss(t_stacks *stack, int print)
{
	int	temp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (print == FLG)
		ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:11:52 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/01 11:12:01 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "../libft/inc/ft_printf.h"

/*	This function swaps every elements in stack a by one place down. */
void	ft_rra(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	if (print == FLG)
		ft_printf("rra\n");
}

/*	This function swaps every elements in stack b by one place down. */
void	ft_rrb(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in STack B.\n");
		return ;
	}
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	if (print == FLG)
		ft_printf("rrb\n");
}

/*	This function swaps every elements in stack a and b by one place down. */
void	ft_rrr(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i--)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = temp;
	if (print == FLG)
		ft_printf("rrr\n");
}

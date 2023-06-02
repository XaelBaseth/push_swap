/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:12:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/01 11:12:09 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "../libft/inc/ft_printf.h"

/*	This function swap every element of stack a by one place up. */
void	ft_ra(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	i = 0;
	temp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = temp;
	if (print == FLG)
		ft_printf("ra\n");
}

/* This function swaps every elements of stack b by one place up.*/
void	ft_rb(t_stacks *stack, int print)
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == STACK)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	i = 0;
	temp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = temp;
	if (print == FLG)
		ft_printf("rb\n");
}

/*	This function swaps every elements of stack a and b by one
	place up. 
*/
void	ft_rr(t_stacks *stack, int print)
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
	i = 0;
	temp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = temp;
	i = 0;
	temp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = temp;
	if (print == FLG)
		ft_printf("rr\n");
}

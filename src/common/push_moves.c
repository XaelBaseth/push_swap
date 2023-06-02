/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:11:44 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/01 11:11:46 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "../libft/inc/ft_printf.h"

/*	This function takes the first element of stack a and put it on
	top of stack b. 
*/
void	ft_pb(t_stacks *stack, int print)
{
	int	i;

	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->a[i] = stack->a[i + 1];
		if (print == FLG)
			ft_printf("pb\n");
	}
	else
	{
		if (print == STACK)
			ft_printf("Nothing done. Stack A is empty.\n");
		return ;
	}
}

/*	This function takes the first element of stack b and put it	on 
	top of stack a. 
*/
void	ft_pa(t_stacks *stack, int print)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->b[i] = stack->b[i + 1];
		if (print == FLG)
			ft_printf("pa\n");
	}
	else
	{
		if (print == STACK)
			ft_printf("Nothing done. Stack B is empty.\n");
		return ;
	}
}

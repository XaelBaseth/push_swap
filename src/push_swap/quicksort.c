/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 08:20:20 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/01 08:20:22 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This function sorts two to three elements by calling the appropriated
	operation using quicksort algorithm. 
*/
void	ft_quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ft_sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, FLG);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack, FLG);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack, FLG);
			else if (len++)
				ft_pa(stack, FLG);
		}
	}
}

/*	This function sort the b stack from one to three elements. */
int	ft_sort_small_b(t_stacks *s, int len)
{
	if (len == 1)
		ft_pa(s, FLG);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s, FLG);
		while (len--)
			ft_pa(s, FLG);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				ft_sa(s, FLG);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 1);
			else
				ft_sb(s, FLG);
		}
	}
	return (0);
}

/* This function allocates memory for a temporary stack in order to
	find the median of a stack. 
*/
int	ft_get_mediane(int *pivot, int *stack, int size)
{
	int	*temp_stack;
	int	i;

	temp_stack = (int *)malloc(size * sizeof(int));
	if (!temp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		temp_stack[i] = stack[i];
		i++;
	}
	ft_sort_tmp(temp_stack, size);
	*pivot = temp_stack[size / 2];
	free(temp_stack);
	return (1);
}

/* This function sorts stack a. It considers different cases based on lenght
	of the stack.
*/
int	ft_quicksort_a(t_stacks *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (ft_check_sorted(stack->a, len, ASCENDING) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_3(stack, len);
		return (1);
	}
	if (!count && !ft_get_mediane(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			ft_pb(stack, FLG);
		else if (++count)
			ft_ra(stack, FLG);
	}
	while (items / 2 + items % 2 != stack->size_a && count--)
		ft_rra(stack, FLG);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
	return (1);
}

/* This function sorts stack a. It considers different cases based on lenght
	of the stack.
*/
int	ft_quicksort_b(t_stacks *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && ft_check_sorted(stack->b, len, DESCENDING) == 1)
		while (len--)
			ft_pa(stack, FLG);
	if (len <= 3)
	{
		ft_sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!ft_get_mediane(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			ft_pa(stack, FLG);
		else if (++count)
			ft_rb(stack, FLG);
	}
	while (items / 2 != stack->size_b && count--)
		ft_rrb(stack, FLG);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}

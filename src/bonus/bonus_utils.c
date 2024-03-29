/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:40:15 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/02 12:40:17 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"

/*	This function checks if the command given is correct. */
int	ft_check_opt(char *opt, t_stacks *stack)
{
	if (ft_strcmp(opt, "sa\n") || ft_strcmp(opt, "sb\n")
		|| ft_strcmp(opt, "ss\n") || ft_strcmp(opt, "ra\n")
		|| ft_strcmp(opt, "rb\n") || ft_strcmp(opt, "rra\n")
		|| ft_strcmp(opt, "rrb\n") || ft_strcmp(opt, "rrr\n")
		|| ft_strcmp(opt, "pa\n") || ft_strcmp(opt, "pb\n")
		|| ft_strcmp(opt, "rr\n"))
		return (1);
	else if (!opt && ft_check_sorted(stack->a, stack->size_a, ASCENDING))
	{
		ft_printf("\033[0;32mOK\n");
		return (0);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
}

/*	Apply the moves to the checker stack. */
void	ft_opt(t_stacks *stack, char *opt)
{
	if (ft_strcmp(opt, "sa\n"))
		ft_sa(stack, STACK);
	else if (ft_strcmp(opt, "sb\n"))
		ft_sb(stack, STACK);
	else if (ft_strcmp(opt, "ss\n"))
		ft_ss(stack, STACK);
	else if (ft_strcmp(opt, "ra\n"))
		ft_ra(stack, STACK);
	else if (ft_strcmp(opt, "rb\n"))
		ft_rb(stack, STACK);
	else if (ft_strcmp(opt, "rr\n"))
		ft_rr(stack, STACK);
	else if (ft_strcmp(opt, "rra\n"))
		ft_rra(stack, STACK);
	else if (ft_strcmp(opt, "rrr\n"))
		ft_rrr(stack, STACK);
	else if (ft_strcmp(opt, "pa\n"))
		ft_pa(stack, STACK);
	else if (ft_strcmp(opt, "pb\n"))
		ft_pb(stack, STACK);
	ft_print_stacks(stack);
}

/*	Print the numbers in the base for the checker. */
void	ft_print_stacks(t_stacks *stack)
{
	int	i;

	i = 0;
	ft_printf("|------------------------------------------------|\n");
	ft_printf("|	Stack A			Stack B		 |\n");
	ft_printf("|	-------			-------		 |\n");
	while (stack->size_a > i || stack->size_b > i)
	{
		if (stack->size_a > i && stack->size_b > i)
		{
			ft_printf("|	%d", stack->a[i]);
			ft_printf("			%d		 |\n", stack->b[i]);
		}
		else if (stack->size_a > i)
			ft_printf("|	%d			-		 |\n", stack->a[i]);
		else
			ft_printf("|	-			%d		 |\n", stack->b[i]);
		i++;
	}
	ft_printf("|------------------------------------------------|\n");
}

/*	Print out the base for the checker program. */
void	ft_checker_start(t_stacks *stack)
{
	int	i;

	i = 0;
	ft_printf("|------------------------------------------------|\n");
	ft_printf("|	Stack A			Stack B		 |\n");
	ft_printf("|	-------			-------		 |\n");
	while (stack->size_a > i)
	{
		ft_printf("|	%d			-		 |\n", stack->a[i]);
		i++;
	}
	ft_printf("|------------------------------------------------|\n");
}

/*	Display the instruction for the checker bonus. */
void	ft_checker_instructions(t_stacks *stack)
{
	ft_printf("|---      Welcome the push_swap checker!      ---|\n");
	ft_printf("|-You will find two stacks below (A and B).      |\n");
	ft_printf("|-The Stack A constains the number with which    |\n");
	ft_printf("|you launched the program.                       |\n");
	ft_printf("|-The Stack B is empty but you can use it to     |\n");
	ft_printf("|get the numbers from Stack A sorted.            |\n");
	ft_printf("|-The avaliable operations are:                  |\n");
	ft_printf("|sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa & pb  |\n");
	ft_printf("|-Write an operation and press return to move    |\n");
	ft_printf("|the numbers.                                    |\n");
	ft_printf("|-If you write a wrong operation the program     |\n");
	ft_printf("|will return an error                            |\n");
	ft_printf("|The goal is to order the number in Stack A      |\n");
	ft_printf("|from the lowest to highest.                     |\n");
	ft_printf("|-If you think you have finished, press the      |\n");
	ft_printf("|return key without writing anything else.       |\n");
	ft_printf("|If the number are sorted, the program will      |\n");
	ft_printf("|show a \033[0;32mOK\033[0;39m message,				 |\n");
	ft_printf("|if not, you will get a \033[0;31mKO\033[0;39m.			 |\n");
	ft_printf("|You can now start writing operations.           |\n");
	ft_printf("|---              Good Luck!                  ---|\n");
	ft_checker_start(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:40:22 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/02 12:40:24 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/get_next_line.h"
#include "../libft/inc/ft_printf.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1)
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

/*	This function checks whether a given input is sorted in ascending order or
	not. 
*/
void	ft_checker(t_stacks *stack)
{
	char		*opt;

	while (1)
	{
		opt = get_next_line(0);
		if (ft_strcmp(opt, "\n"))
		{
			if (ft_check_sorted(stack->a, stack->size_a, ASCENDING)
				&& stack->size_b == 0)
				ft_printf("\033[0;32mOK\n");
			else
				ft_printf("\033[0;31mK0\n");
			free(stack->a);
			free(stack->b);
			exit (1);
		}
		if (!ft_check_opt(opt, stack))
		{
			free(stack->a);
			free(stack->b);
			return ;
		}
		ft_opt(stack, opt);
	}
}

/*	This function looks for error in the given parameters of the checker. */
int	*ft_check_errors(char **argv)
{
	int	*a;
	int	size;
	int	i;

	i = -1;
	size = ft_ps_strlen(argv);
	a = malloc(size * sizeof(int));
	while (++i < size)
		a[i] = ft_ps_atoi(argv[i], a);
	ft_check_repeat(a, size);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		stack.a = ft_check_errors(argv);
		stack.size_a = ft_ps_strlen(argv);
		ft_checker_instructions(&stack);
		stack.b = malloc(stack.size_a * sizeof(int));
		if (!stack.b)
		{
			free(stack.a);
			return (0);
		}
		stack.size_b = 0;
		ft_checker(&stack);
	}
	return (0);
}

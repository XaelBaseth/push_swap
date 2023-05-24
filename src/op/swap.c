#include "push_swap.h"

/*	Swap the first two elements in the pile A. */
void	swap_stack_a(long *pile_a, int *nums_in_a)
{
	long *temp;

	temp = (long *)malloc(sizeof(long));
	if (nums_in_a[1] > 1)
	{
		temp[0] = pile_a[0];
		pile_a[0] = nums_in_a[1];
		nums_in_a[1] = temp[0];
	}
	free(temp);
	write(1, "sa\n", 3);
}

/*	Swap the first two elements in the pile B. */
void	swap_stack_b(long *pile_b, int *nums_in_b)
{
	long	*temp;
	
	temp = (long *)malloc(sizeof(long));
	if (*nums_in_b > 1)
	{
		temp[0] = pile_b[0];
		pile_b[0] = pile_b[1];
		pile_b[1] = temp[0];
	}
	free(temp);
	write(1, "sb\n", 3);
}

/*	Swap the first elements in the piles A and B. */
void	swap_stack_a_and_stack_b(long *pile_a, long *pile_b, int *nums_in_a, int *nums_in_b)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (nums_in_a[1] > 1)
	{
		temp[0] = pile_a[0];
		pile_a[0] = pile_a[1];
		pile_a[0] = temp[0];
	}
	if (*nums_in_b > 1)
	{
		temp[0] = pile_b[0];
		pile_b[0] = pile_b[1];
		pile_b[1] = temp[0];
	}
	free(temp);
	write(1, "ss\n", 3);
}

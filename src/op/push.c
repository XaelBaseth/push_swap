#include "push_swap.h"

/* Function that pushes the top element of pile B on top of pile A. */
void	push_stack_a(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	int	i;

	(num_in_a[1])++;
	i = num_in_a[1] - 1;
	while (i > 0)
	{
		pile_a[i] = pile_a[i - 1];
		i--;
	}
	pile_a[0] = pile_b[0];
	i = 0;
	while (i < *num_in_b)
	{
		pile_b[i] = pile_b[i + 1];
		i++;
	}
	(*num_in_b)--;
	if (*num_in_b == 0)
		pile_b = NULL;
	write(1, "Push Stack A\n", 14);
}

/* Function that pushes the top element of pile A on pile top of pile B*/
void	push_stack_b(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	int	i;

	(*num_in_b)++;
	i = *num_in_b - 1;
	while (i > 0)
	{
		pile_b[i] = pile_b[i - 1];
		i--;
	}
	pile_b[0] = pile_a[0];
	i = 0;
	while ( i < num_in_a[1])
	{
		pile_a[i] = pile_a[i + 1];
		i++;
	}
	(num_in_a[1])--;
	if (num_in_a[1] == 0)
		pile_a = NULL;
	write(1, "Push Stack B\n", 1);
}
#include "push_swap.h"

/*	Rotate element in pile A in descending order. The last element
	become the first. */
void	reverse_rotate_stack_a(long *pile_a, int *nums_in_a)
{
	long	*temp;
	int		i;
	
	i = nums_in_a[1] - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = pile_a[nums_in_a[1] - 1];
	while (i > 0)
	{
		pile_a[i] = pile_a[i - 1];
		i--;
	}
	pile_a[0] = *temp;
	free(temp);
	write(1, "Reverse Rotate Stack A\n", 24);
}

/*	Rotate element in pile B in descending order. The last element
	become the first. */
void	reverse_rotate_stack_b(long *pile_b, int *nums_in_b)
{
	long	*temp;
	int		i;

	i = *nums_in_b - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = pile_b[*nums_in_b - 1];
	while (i > 0)
	{
		pile_b[i] = pile_b[i - 1];
		i--;
	}
	pile_b[0] = *temp;
	free(temp);
	write(1, "Reverse Rotate Stack B\n", 24);
}
/*	Rotate element in pile B and pile A in descending order. The last 
	element become the first. */
void	reverse_rotate_stack_a_and_stack_b(long *pile_a, long *pile_b, int *nums_in_a, int *nums_in_b)
{
	long	*temp;
	int		i;

	i = nums_in_b[1] - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = pile_a[nums_in_a[1] - 1];
	while (i > 0)
	{
		pile_a[i] = pile_a[i - 1];
		i--;
	}
	pile_a[0] = *temp;
	while (i < *nums_in_b)
	{
		pile_b[i] = pile_b[i + 1];
		i++;
	}
	pile_b[*nums_in_b - 1] = *temp;
	free(temp);
	write(1, "Reverse Rotate both Stack A and B\n", 35);
}
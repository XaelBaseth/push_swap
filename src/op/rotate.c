#include "push_swap.h"

/*	Rotate every element in pile A toward the top. The first
	element become the last. */
void	rotate_pile_a(long *pile_a, int *nums_in_a)
{
	long	*temp;
	int		i;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	*temp = pile_a[0];
	while (i < nums_in_a[1])
	{
		pile_a[i] = pile_a[i + 1];
		i++;
	}
	pile_a[nums_in_a[1] - 1] = *temp;
	free(temp);
	write(1, "Rotate Stack A\n", 16);
}

/*	Rotate every element in pile B toward the top. The first
	element become the last. */
void	rotate_pile_b(long *pile_b, int *nums_in_b)
{
	long	*temp;
	int		i;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	*temp = pile_b[0];
	while (i < *nums_in_b)
	{
		pile_b[i] = pile_b[i + 1];
		i++;
	}
	pile_b[*nums_in_b - 1] = *temp;
	free(temp);
	write(1, "Rotate Stack B\n", 16);
}

/*	Rotate every element in pile B and A toward the top. The first
	element become the last. */
void	rotate_pile_a_and_pile_b(long *pile_a, long *pile_b, int *nums_in_a, int *nums_in_b)
{
	long	*temp;
	int		i;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	*temp = pile_a[0];
	while (i < pile_a[1])
	{
		pile_a[i] = pile_a[i + 1];
		i++;
	}
	pile_a[nums_in_a[1] - 1] = *temp;
	i = 0;
	*temp = pile_b[0];
	while (i < *nums_in_b)
	{
		pile_b[i] = pile_b[i + 1];
		i++;
	}
	pile_b[*nums_in_b - 1] = *temp;
	free(temp);
	write(1, "Rotate both Stack A and B\n", 27);
}
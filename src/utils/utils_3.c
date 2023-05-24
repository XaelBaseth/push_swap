#include "push_swap.h"

/* Check if the integer is a single digit or not. */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*	Check that the pile A is sorted in ascending order by comparing
	each element with the maximum value found so far. */
int	is_stack_sorted(long *pile_a, int *num_in_a)
{
	int		i;
	int		j;
	long	max;

	i = 1;
	j = 0;
	max = pile_a[0];
	while (i < num_in_a[1])
	{
		if (pile_a[i] > max)
		{
			max = pile_a[i];
			j++;
		}
		i++;
	}
	if (j == num_in_a[1] - 1)
		return (0);
	return (-1);
}

/*	Free the everything and exit the program. */
void	free_stack(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	free(pile_a);
	free(pile_b);
	free(num_in_a);
	free(num_in_b);
	exit(0);
}

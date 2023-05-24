#include "push_swap.h"

/*	Sort a section of the pile throug bubble sort algorithm. */
void	sort_a_section(long *array, int *pile_size)
{
	long	i;
	long	j;
	long	temp;

	i = 0;
	j = 0;
	while (i <pile_size[0])
	{
		j = i + 1;
		while (j < pile_size[0])
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/*	This function copies the content of pile A into copy and copy_swap. */
void	copy_stack_a(long *copy, long *copy_swap_a, long *pile_a, int *num_in_a)
{
	int	i;

	i = 0;
	while (i < num_in_a[0])
	{
		copy[i] = pile_a[i];
		copy_swap_a[i] = pile_a[i];
		i++;
	}
}

/*	Performs a mapping operation (assign each element of one set to another 
	set) of copy and copy_swap_a to pile A.*/
void	mapping_to_a(long *copy, long *copy_swap_a, long *pile_a, int *num_in_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num_in_a[1])
	{
		j = 0;
		while (j < num_in_a[0])
		{
			if (copy_swap_a[i] == copy[j])
				pile_a[i] = j;
			j++;
		}
		++i;
	}
}

/*	Performs a bitwise operation on a pile A element and moves it either to
	pile A or pile B. */
void	swap_stack_a_third_time(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	int	max_number;
	int max_bits;
	int	loop_through[2];

	max_number = num_in_a[1] - 1;
	max_bits = 0;
	loop_through[0] = 0;
	loop_through[1] = 0;
	while ((max_number >> max_bits) != 0)
		++max_bits;
	while (loop_through[0] < max_bits)
	{
		loop_through[1] = 0;
		while (loop_through[1] < num_in_a[0])
		{
			if (((pile_a[0] >> loop_through[0]) & 1) == 1)
				rotate_pile_a(pile_a, num_in_a);
			else
				push_stack_b(pile_a, pile_b, num_in_a, num_in_b);
			++loop_through[1];
		}
		while (*num_in_b != 0)
			push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		++loop_through[0];
	}
}

/*	Performs a sorting operation on pile A elements and move them to pile A
	or pile B.*/
void	sort_beyond_3_and_5_numbers(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	long	*copy;
	long	*copy_swap_a;

	copy = (long *)malloc(num_in_a[0] * sizeof(long));
	copy_swap_a = (long *)malloc(num_in_a[0] * sizeof(long));
	copy_stack_a(copy, copy_swap_a, pile_a, num_in_a);
	sort_a_section(copy, num_in_a);
	mapping_to_a(copy, copy_swap_a, pile_a, num_in_a);
	free(copy);
	free(copy_swap_a);
	swap_stack_a_third_time(pile_a, pile_b, num_in_a, num_in_b);
}
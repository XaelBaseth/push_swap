#include "push_swap.h"

/*	Sort the the pile A and B by using the allowed operations. */
void	first_stack(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	if (pile_b[0] < pile_a[0])
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
	else if ((pile_b[0] > pile_a[0]) && (pile_b[0] < pile_a[1]))
	{
		rotate_pile_a(pile_a, num_in_a);
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		reverse_rotate_stack_a(pile_a, num_in_a);
	}
	else if ((pile_b[0] > pile_a[1]) && (pile_b[0] < pile_a[2]))
	{
		reverse_rotate_stack_a(pile_a, num_in_a);
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		reverse_rotate_stack_a(pile_a, num_in_a);
		reverse_rotate_stack_a(pile_a, num_in_a);
	}
	else if (pile_b[0] > pile_a[2])
	{
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		rotate_pile_a(pile_a, num_in_a);
	}
}

/*	Sort the the pile A and B by using the allowed operations. */
void	second_stack(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	if (pile_b[0] < pile_a[0])
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
	else if ((pile_b[0] > pile_a[0]) && (pile_b[0] < pile_a[1]))
	{
		rotate_pile_a(pile_a, num_in_a);
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		reverse_rotate_stack_a(pile_a, num_in_a);
	}
	else if ((pile_b[0] > pile_a[1]) && (pile_b[0] < pile_a[2]))
	{
		rotate_pile_a(pile_a, num_in_a);
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		swap_stack_a(pile_a, num_in_a);
		reverse_rotate_stack_a(pile_a, num_in_a);
	}
	else if ((pile_b[0] > pile_a[2]) && (pile_b[0] < pile_a[3]))
	{
		reverse_rotate_stack_a(pile_a, num_in_a);
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		rotate_stack_a(pile_a, num_in_a);
		rotate_stack_a(pile_a, num_in_a);
	}
	else if (pile_b[0] > pile_a[3])
	{
		push_stack_a(pile_a, pile_b, num_in_a, num_in_b);
		rotate_stack_a(pile_a, num_in_a);
	}
}

/*	Sort the five first element by pushing two on top of pile B and sorting,
	the three left in pile A. It then sort the two B elements according
	to what is needed wether there is four or five elements in pile A. */
void	sort_5_numbers(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b)
{
	push_stack_b(pile_a, pile_b, num_in_a, num_in_b);
	push_stack_b(pile_a, pile_b, num_in_a, num_in_b);
	sort_3_numbers(pile_a, num_in_a);
	while (*num_in_b != 0)
	{
		if (num_in_a[1] == 3)
			first_stack(pile_a, pile_b, num_in_a, num_in_b);
		else if (num_in_a[1] == 4)
			second_stack(pile_a, pile_b, num_in_a, num_in_b);
	}
}
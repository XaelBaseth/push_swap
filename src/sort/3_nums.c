#include "push_swap.h"

/*	Sort the first three elements of the pile A by checking which elements
	are sorted or not and applying the proper operations. (> is unsorted) */
void	sort_3_numbers(long *pile_a, int *nums_in_a)
{
	if ((pile_a[0] > pile_a[1]) && (pile_a[1] < pile_a[2]) && (pile_a[0] < pile_a[2]))
		swap_stack_a(pile_a, nums_in_a);
	if ((pile_a[0] > pile_a[1]) && (pile_a[1] > pile_a[2]) && (pile_a[0] > pile_a[2]))
	{
		swap_stack_a(pile_a, nums_in_a);
		reverse_rotate_stack_a(pile_a, nums_in_a);
	}
	if ((pile_a[0] > pile_a[1]) && (pile_a[1] < pile_a[2]) && (pile_a[0] > pile_a[2]))
		rotate_pile_a(pile_a, nums_in_a);
	if ((pile_a[0] < pile_a[1]) && (pile_a[1] > pile_a[2]) && (pile_a[0] < pile_a[2]))
	{
		swap_stack_a(pile_a, nums_in_a);
		rotate_pile_a(pile_a, nums_in_a);
	}
	if ((pile_a[0] < pile_a[1]) && (pile_a[1] > pile_a[2]) && (pile_a[0] > pile_a[2]))
		reverse_rotate_stack_a(pile_a, nums_in_a);
}
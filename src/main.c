#include "push_swap.h"

/*	Free the pile A & B with an "Error" message. */
void	free_and_exit_with_error(int *nums_in_a, int *nums_in_b)
{
	free(nums_in_a);
	free(nums_in_b);
	write(1, "Error: invalid input parameters\n", 33);
	exit(0);
}

/*	Ensure that given parameters are correct (2 parameters, list of integers). */
void	check_params(int argc, char **argv, int *nums_in_a, int *nums_in_b)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc < 2)
		free_and_exit_with_error(nums_in_a, nums_in_b);
	while (i < argc)
	{
		if ((argv[i][ft_strlen(argv[i]) - 1] == 32)|| (argv[i][0] == 32))
			free_and_exit_with_error(nums_in_a, nums_in_b);
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (((argv[i][j] < 48) || (argv[i][j] > 57)) && (argv[i][j] != 32))
			{
				if (argv[i][j] != 45)
					free_and_exit_with_error(nums_in_a, nums_in_b);
			}
			if ((argv[i][j] == 32) && argv[i][j + 1] == 32)
				free_and_exit_with_error(nums_in_a, nums_in_b);
			j++;
		}
		i++;
	}
}

/* Iniatilize the pile A and B and filling the pile A with the numbers. */
void	set_numbers(int *nums_in_a, int *nums_in_b, int argc)
{
	nums_in_a[0] = argc - 1;
	nums_in_a[1] = nums_in_a[0];
	*nums_in_b = 0; 
}

/*	The main function check if the parameters given are corrects, then
	initialize the numbers in pile A. We then uses a quicksort algorithm 
	to sort the numbers for three, five or more elements. And, finally,
	we free	the piles. */
int	main(int argc, char **argv)
{
	long	*pile_a;
	long	*pile_b;
	int		*nums_in_a;
	int		*nums_in_b;

	nums_in_a = (int *)malloc(2 * sizeof(int)); //2 * => store two values: size of stack A and numbers of arg passed
	nums_in_b = (int *)malloc(sizeof(int));
	check_params(argc, argv, nums_in_a, nums_in_b);
	set_numbers(nums_in_a, nums_in_b, argc);
	pile_a = (long *)malloc(sizeof(long) * stack_size(argc, argv));
	pile_b = (long *)malloc(sizeof(long) * stack_size(argc, argv));
	if ((separating_input_numbers(pile_a, nums_in_a, argv) == -1) || (is_stack_sorted(pile_a, nums_in_a) == 0))
		free_stack(pile_a, pile_b, nums_in_a, nums_in_b);
	if ((nums_in_a[1] == 2) && (pile_a[0] > pile_a[1]))
		rotate_pile_a(pile_a, nums_in_a);
	else if (nums_in_a[1] == 3)
		sort_3_numbers(pile_a, nums_in_a);
	else if (nums_in_a[1] == 5)
		sort_5_numbers(pile_a, pile_b, nums_in_a, nums_in_b);
	else
		sort_beyond_3_and_5_numbers(pile_a, pile_b, nums_in_a, nums_in_b);
	free_stack(pile_a, pile_b, nums_in_a, nums_in_b);
	return (0);
}
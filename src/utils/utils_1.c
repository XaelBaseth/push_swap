#include "push_swap.h"

/* Return an int from a string. */
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0'  && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}

/* Free the string. */
void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

/*	Takes the input string and split it into indiviual string with a space as
	a delimitor. It then convert every string into int and store them into
	the pile A. */
int	number_input(long *pile_a, int *num_in_a, char **argv, char **num_list)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	num_list = ft_split(argv[1], 32);
	while (num_list[i])
	{
		nums++;
		i++;
	}
	num_in_a[0] = nums;
	num_in_a[1] = num_in_a[0];
	i = 0;
	while (i < num_in_a[0])
	{
		pile_a[i] = ft_atoi(num_list[i]);
		i++;
	}
	free_string(num_list);
	free(num_list);
	return (0);
}

/*	Have a similar purpose as number_input() but from a different input.
	This function receives the integers as individual argument (not a
	string) and check their validity before storing them in pile A. */
int	standard_input(long *pile_a, int *num_in_a, char **argv)
{
	int	i;

	i = 0;
	while (i < num_in_a[1])
	{
		if (is_only_number_in_stack(argv[i + 1]) == 1)
			pile_a[i] = ft_atoi(argv[i + 1]);
		else
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

/*	Verify the input and the way it should be separated according to differents
	cases.*/
int	separating_input_numbers(long *pile_a, int *num_in_a, char **argv)
{
	char	**nums_list;

	nums_list = NULL;
	if (num_in_a[0] == 1)
	{
		if (number_input(pile_a, num_in_a, argv, nums_list) == -1)
			return (-1);
	}
	else
	{
		if (standard_input(pile_a, num_in_a, argv) == -1)
			return (-1);
	}
	if (repeated_numbers(pile_a, num_in_a[1]) == -1)
		return (-1);
	if (number_limit (pile_a, num_in_a[1]) == -1)
		return (-1);
	return (0);
}
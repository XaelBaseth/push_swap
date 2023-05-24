#include "push_swap.h"

/* Print out the lenght of a string. */
int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* Print out the size of the stack. */
int	stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
				size++;
			i++;
		}
	}
	else
		size = argc - 1;
	return (size);
}

/*	Check for every duplicated number. */
int	repeated_numbers(long *pile_a, int num_in_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num_in_a)
	{
		j = 0;
		while (j < num_in_a)
		{
			if ((pile_a[i] == pile_a[j]) && i != j)
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/* Check that every number is a int. */
int	number_limit(long *pile_a, int num_in_a)
{
	int	i;

	i = 0;
	while (i < num_in_a)
	{
		if ((pile_a[i] > INT_MAX) ||(pile_a[i] < INT_MIN))
		{
			write(1, "Error\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

/* Check if the input string contains only a single integer. */
int	is_only_number_in_stack(char *num)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (num[i])
	{
		if (num[i] == 45)
			minus++;
		else if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	if (minus > 1)
		return (0);
	return (1);
}
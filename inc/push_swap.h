#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	ft_atoi(char *str);
int	ft_isdigit(int i);
int	stack_size(int argc, char **argv);
int	number_limit(long *pile_a, int *num_in_a);
int	repeated_numbers(long *pile_a, int *num_in_a);
int	separating_input_numbers(long *pile_a, int *num_in_a, char **argv);
int	standard_input(long *pile_a, int *num_in_a, char **argv);
int	number_input(long *pile_a, int *num_in_a, char **argv, char **num_list);
int	is_stack_sorted(long *pile_a, int *num_in_a);

void	free_string(char **str);
void	free_stack(long *pile_a, long *pile_b, int *num_in_a, int num_in_b);

void	rotate_pile_a(long *pile_a, int *nums_in_a);
void	rotate_pile_b(long *pile_b, int *nums_in_b);
void	rotate_pile_a_and_pile_b(long *pile_a, long *pile_b, int *nums_in_a, int *nums_in_b);
void	swap_stack_a(long *pile_a, int *nums_in_a);
void	swap_stack_b(long *pile_b, int *nums_in_b);
void	swap_stack_a_and_stack_b(long *pile_a, long *pile_b, int *nums_in_a, int *nums_in_b);
void	reverse_rotate_stack_a(long *pile_a, int *nums_in_a);
void	reverse_rotate_stack_b(long *pile_b, int *nums_in_b);
void	reverse_rotate_stack_a_and_stack_b(long *pile_a, long *pile_b, int *nums_in_a, int *nums_in_b);
void	push_stack_a(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b);
void	push_stack_b(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b);

void	sort_3_numbers(long *pile_a, int *nums_in_a);
void	sort_5_numbers(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b);
void	sort_beyond_3_and_5_numbers(long *pile_a, long *pile_b, int *num_in_a, int *num_in_b);

char	**ft_split(char const *s, char c);

#endif
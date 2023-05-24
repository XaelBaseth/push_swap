#include "push_swap.h"

/*	Count the words in the string separated by the character with the help of a
	flag to indicate the the word has ended. */
static int	count_words(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (*str)
	{
		if (*str != c && counter == 0)
		{
			counter = 1;
			i++;
		}
		else if (*str == c)
			counter = 0;
		str++;
	}
	return (i);
}

/*	Copy a portion of the input string between start and finish to 
	an allocated string. */
static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

/*	Split the string into arrays using the delimiter character. */
char	**ft_split(char *s, char c)
{
	int	i;
	int	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
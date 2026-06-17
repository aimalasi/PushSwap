/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:57 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/06 15:00:10 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == ' ')
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*get_word(char *s, int *i)
{
	char	*word;
	int		start;
	int		len;

	while (s[*i] == ' ')
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != ' ')
		(*i)++;
	len = *i - start;
	word = malloc((sizeof(char)) * (len + 1));
	if (!word)
		return (NULL);
	ft_strncpy(word, s + start, len);
	word[len] = '\0';
	return (word);
}

static char	**split_string(char *s, int count)
{
	char	**result;
	int		i;
	int		j;

	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		result[j] = get_word(s, &i);
		if (!result[j])
			return (NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}

static char **parse_args(int argc, char **argv, int *size)
{
	if (argc == 2)
	{
		*size = count_words(argv[1]);
		args = split_string(argv[1], *size);
	}
	*size = argc - 1;
	return (argv + 1);
}

static void	load_stack(t_stack *a, t_stack *b, char **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_valid_int(args[i]))
		{
			if (size == 2)
				free_split(args);
			error_exit(a, b);
		}
		a->arr[size - 1 - i] = atoll(args[i]);
		i++;
	}
	a->top = size - 1;
	b->top = -1;
	if (has_duplicates(a, size))
	{
		if (size == 2)
			free_split(args);
		error_exit(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	**args;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		size = count_words(argv[1]);
		args = split_string(argv[1], size);
	}
	else
	{
		args = argv + 1;
		size = argc - 1;
	}
	if (!args || size == 0)
	{
		if (argc == 2)
			free_split(args);
		return (0);
	}
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
	{
		if (argc == 2)
			free_split(args);
		error_exit(a, b);
	}
	load_stack(a, b, args, size);
	if (argc == 2)
		free_split(args);
	if (is_sorted(a))
		return (free_stack(a), free_stack(b), 0);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		normalize(a, size);
		radix_sort(a, b, size);
	}
	return (free_stack(a), free_stack(b), 0);
}

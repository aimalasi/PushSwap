/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:33:19 by aimalasi          #+#    #+#             */
/*   Updated: 2026/06/25 17:21:37 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s)
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

char	*get_word(char *s, int *i)
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

char	**split_string(char *s, int count)
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

void	load_stack(t_stack *a, t_stack *b, char **args, int size)
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

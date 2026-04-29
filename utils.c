/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:35:05 by aimalasi          #+#    #+#             */
/*   Updated: 2026/04/24 18:34:42 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->arr[a->top] > a->arr[a->top - 1])
		swap(a, "sa");
}

t_stack *init_stack(int size)
{
	t_stack *s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->arr = malloc(sizeof(int) * size);
	if (!s->arr)
	{
		free(s);
		return (NULL);
	}
	s->top = -1;
	s->size = size;
	return (s);
}

void    free_stack(t_stack *s)
{
	if (!s)
		return ;
	free(s->arr);
	free(s);
}

void    error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_valid_int(char *s)
{
	long long	n;
	int			i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	n = atoll(s);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *a, int size)
{
	int i;
	int	j;
	
	if (size == 1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a->arr[i] == a->arr[j])
				return (1);
			j++;
		}
		i++;
		if (i == size - 1)
		 break ;
	}
	return (0);
}

int is_sorted(t_stack *a)
{
	int i;

	i = 0;
	while (i < a->top)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
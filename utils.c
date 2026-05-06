/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:35:05 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/05 19:48:36 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->arr[a->top] > a->arr[a->top - 1])
		swap(a, "sa");
}

t_stack	*init_stack(int size)
{
	t_stack	*s;

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

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	free(s->arr);
	free(s);
}

void	error_exit(t_stack *a, t_stack *b)
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

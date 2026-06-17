/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:18:28 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/06 14:56:01 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int t;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	normalize(t_stack *a, int size)
{
	int	*sorted;
	int	*tmp;
	int	i;
	int	j;

	sorted = malloc(sizeof(int) * size);
	tmp = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		tmp[i] = a->arr[i];
		sorted[i] = a->arr[i];
		i++;
	}
	bubble_sort(sorted, size);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (sorted[j] != tmp[i])
			j++;
		a->arr[i] = j;
		i++;
	}
	free(sorted);
	free(tmp);
}

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((1 << max_bits) <= size - 1)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b, int size)
{
	int bit;
	int max_bits;
	int i;

	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->arr[a->top]) >> bit) & 1)
				rotate(a, "ra");
			else
				push(b, a, "pb");
			i++;
		}
		while (b->top >= 0)
			push(a, b, "pa");
		bit++;
	}
}

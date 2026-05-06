/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:18:28 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/05 19:46:04 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j <size -1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int t = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
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

void	radix_sort(t_stack *a, t_stack *b, int size)
{
	int bit;
	int max_bits;
	int i;
	int max_val;

	max_val = size - 1;
	max_bits = 0;
	while ((1 << max_bits) <= max_val)
		max_bits++;

	bit = 0;
	while (bit <max_bits)
	{
		i = 0;
		while (i <size)
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
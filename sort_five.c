/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:27:13 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/05 19:47:43 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_stack *a)
{
	int	i;
	int	min;
	int	pos;

	i = a->top;
	min = a->arr[i];
	pos = i;
	while (i >= 0)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			pos = i;
		}
		i--;
	}
	return (pos);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	while (size > 3)
	{
		while (a->top != get_min_pos(a))
		{
			if (get_min_pos(a) > a->top / 2)
				rotate(a, "ra");
			else
				reverse_rotate(a, "rra");
		}
		push(b, a, "pb");
		size--;
	}
	sort_three(a);
	while (b->top >= 0)
		push(a, b, "pa");
}

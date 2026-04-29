/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:15:57 by aimalasi          #+#    #+#             */
/*   Updated: 2026/04/24 17:47:28 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_upper(t_stack *a, int top, int mid, int bot)
{
	if (top > mid && top < bot)
		swap (a, "sa");
	else if (top > mid && top > bot && mid > bot)
	{
		rotate(a, "ra");
		swap(a, "sa");
	}
	else if (top > mid && top > bot && mid < bot)
		rotate(a, "ra");
}

static void sort_three_lower(t_stack *a, int top, int mid, int bot)
{
	if (top < mid && top > bot)
		reverse_rotate(a, "rra");
	else if (top < mid && top < bot && mid > bot)
	{
		reverse_rotate(a, "rra");
		swap(a, "sa");
	}
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;
	
	top = a->arr[a->top];
	mid = a->arr[a->top - 1];
	bot = a->arr[a->top - 2];
	sort_three_upper(a, top, mid, bot);
	sort_three_lower(a, top, mid, bot);
}

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:15:57 by aimalasi          #+#    #+#             */
/*   Updated: 2026/05/05 19:46:49 by aimalasi         ###   ########.fr       */
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

static void	sort_three_lower(t_stack *a, int top, int mid, int bot)
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

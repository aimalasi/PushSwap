/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:57 by aimalasi          #+#    #+#             */
/*   Updated: 2026/03/24 16:11:53 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a)
{
	int i;

	i = a->top;
	while (i > 0)
	{
		if (a->arr[i] < a->arr[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		size;
	int		i;

	if (argc < 2)
		return (0);
	size = argc - 1;
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
		error_exit(a, b);

	i = 0;
	while (i < size)
	{
		a->arr[i] = atoll(argv[i + 1]);
		a->top = size - 1;
	}
	a->top = size - 1;
	b->top = -1;

	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	normalize(a, size);
	radix_sort(a, b, size);

	free_stack(a);
	free_stack(b);
	return (0);
}
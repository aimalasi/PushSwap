/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:57 by aimalasi          #+#    #+#             */
/*   Updated: 2026/06/25 16:35:40 by aimalasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_stack(int argc, char **args, t_stack *a, t_stack *b)
{
	if (!a || !b)
	{
		if (argc == 2)
			free_split(args);
		error_exit(a, b);
	}
}

static int	check_zero_size(int argc, int size, char **args)
{
	if (!args || !size)
	{
		if (argc == 2)
			free_split(args);
		return (0);
	}
	return (1);
}

static int	check_args(int argc, char **argv, int *size, char ***args)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		*size = count_words(argv[1]);
		*args = split_string(argv[1], *size);
	}
	else
	{
		*size = argc - 1;
		*args = argv + 1;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	**args;

	if (!check_args(argc, argv, &size, &args))
		return (0);
	if (!check_zero_size(argc, size, args))
		return (0);
	a = init_stack(size);
	b = init_stack(size);
	(check_stack(argc, args, a, b), load_stack(a, b, args, size));
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
		(normalize(a, size), radix_sort(a, b, size));
	return (free_stack(a), free_stack(b), 0);
}
